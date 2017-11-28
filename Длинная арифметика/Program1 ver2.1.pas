Program Ex_1;

const
  n = 50;
  m = 8;
  
type
  RealNumber = record // Многоразрядное вещественное число
    IntPart: array [0 .. n+1] of word;
    RealPart: array [0 .. n] of word;
    end;
  NumbersWithZero = set of char;
  Numbers = set of char;
    
var
  inf, outf: text;
  RealNumber1, RealNumber2, SubNumbers, SumNumbers: RealNumber;
  i: byte;
  dg0: NumbersWithZero := ['0' .. '7', '.'];
  dg: Numbers := ['1' .. '7', '.'];
  
  {Переворачивание последнего разряда в дробной части числа}
  function last_convert (x:RealNumber):string; 
    
    var
      s,s1:string;
      i: byte;
      
    begin
      s := IntToStr(x.RealPart[x.RealPart[0]]);
      for i := 1 to length(s) do
        begin
          s1 := s[i] + s1;
        end;
      last_convert := s1;
    end;
 
 {Разбивание разряда из дробной части числа на сотни, десятки и еденицы (для сложения и вычитания)}
  procedure toRealParts (x:RealNumber; var a,b,c:integer;i:integer);
          
    var
     a0:integer;
     s:string;
          
    begin
      if (i = x.RealPart[0]) then
        begin
          s := last_convert(x);
          if (length(s) = 3)then
            begin
              a := StrToInt(s[1]);
              b := StrToInt(s[2]);
              c := StrToInt(s[3]);
            end
          else
            if (length(s) = 2) then
              begin
                a := StrToInt(s[1]);
                b := StrToInt(s[2]);
                c := 0;
              end
            else
              begin
                a := StrToInt(s[1]);
                b := 0;
                c := 0;
              end;
        end
      else
        begin
          a := x.RealPart[i] div 100;
          a0 := x.RealPart[i] mod 100;
          b := a0 div 10;
          c := x.RealPart[i] mod 10;
        end;
    end;
 
 {Разбиванеи разряда из целой части числа на сотни, десятки и еденицы (для сложения и вычитания)}
  procedure toIntParts (x:RealNumber; var a,b,c:integer;i:integer);
          
    var
      a0:integer;
      s:string;
          
    begin
      a := x.IntPart[i] div 100;
      a0 := x.IntPart[i] mod 100;
      b := a0 div 10;
      c := x.IntPart[i] mod 10;
    end;  
  
  {Считывание числа из файла}
  function ReadRealNumber (f: text; var x: RealNumber): boolean;
    
    var
      i,l1,l:word;
      k, count,d1,d2: byte;
      s,str,s1,s2: string;
      b: boolean; // правильность введённого числа
      
    begin
      readln(f,s);
      b := true; 
      count := 0;
      l := 1;
      d1 := -1;
      d2 := 0;
      s := '0' + s;
      if (length(s) = 1) then // Для случая, когда строка пустая
        b := false;
      if b and ((s[1] = '.') or (s[length(s)] = '.') or not (s[1] in dg0) or not (s[length(s)] in dg0)) then // Проверка первого символа на правильность
        b := false;
      while (l <= length(s)) and (not (s[l] in dg)) and (b = true) do // Отсекание незначащих нулей в целой части
        begin
          d1 := d1+1;
          if not (s[l] in dg0) then
            b := false;
          l := l+1;
        end;
      if l > length(s)then // Для случая, когда в строке все нули (без точки)
        b := false;
      if (b = true) and (s[l] = '.') then // Для случая, когда в целой части все нули
        x.IntPart[0] := x.IntPart[0] + 1;
      l1 := length(s);
      while (b = true) and not (s[l1] in dg) do // Отсекание незначащих нулей в дробной части
        begin
          l1 := l1-1;
          d2 := d2+1;
          if not (s[l1] in dg0) then
            b := false;
        end;
      if (b = true) and (s[l1] = '.') then // Для случая, когда в дробной части все нули
        x.RealPart[0] := x.RealPart[0] + 1;
      while (l <= l1) and (b = true) do // Проверка числа на правильность
        begin
          if not (s[l] in dg0) then 
            b := false
          else
            if s[l] = '.' then // Считает кол-во точек в числе
              begin
                count := count + 1;
                l := l + 1;
                if count = 2 then
                  b := false;
              end
            else
              if count = 0 then
                begin
                  s1 := s1 + s[l];
                  l := l+1;
                  d1 := d1+1;
                end
              else
                begin
                  s2 := s2 + s[l];
                  l := l+1;
                  d2 := d2+1;
                end;
        end;
      if (d1 > n*3) or (d2 > n*3) then // Для случая, когда в целой или в целой части больше 150 цифр
        b := false;
      if (count = 0) then // Для случая, когда в числе нету точек
        b := false;
      if b = true then // Елси число введено правильно, то разбиваем его на части по 3 цифры
        begin
          i := length(s1);
          while (i >= 1) do // Разбивание целой части (с конца)
            begin
              str := '';
              for k := 1 to 3 do
                begin
                  if (i >= 1) then
                    begin
                      str := s1[i] + str;
                      i := i - 1;
                    end;
                end;
              if (str <> '') then
                begin
                  x.IntPart[0] := x.IntPart[0] + 1;
                  x.IntPart[x.IntPart[0]] := StrToInt(str);
                end;
            end;
          i := 1;
          while (i <= length(s2)) do // Разбивание дробной части
            begin
              str := '';
              if (i <= length(s2)-3) then
                begin
                  for k := 1 to 3 do
                    if (i <= length(s2)) then
                      begin
                        str := str + s2[i];
                        i := i + 1;
                      end;
                end
              else
                begin
                  for k := 1 to 3 do
                    if (i <= length(s2)) then
                      begin
                        str := s2[i] + str;
                        i := i + 1;
                      end;
                end;
              if (str <> '') then
                begin
                  x.RealPart[0] := x.RealPart[0] +1;
                  x.RealPart[x.RealPart[0]] := StrToInt(str); 
                end;
            end;
        end;
      ReadRealNumber := b;
    end;
    
  {Печать числа в файл}
  procedure WriteRealNumber (var t:text; x: RealNumber);
    
    var
      k,i: byte;
    
    begin
      k := x.IntPart[0];
      write(t,x.IntPart[k]);
      for i := k-1 downto 1 do
        begin
          if (x.IntPart[i] < 10) then
            write(t,'00'+x.IntPart[i])
          else
            if (x.IntPart[i] < 100) then
              write(t,'0'+x.IntPart[i])
            else
              write(t,x.IntPart[i]);
        end;
      k := x.RealPart[0];
      write(t,'.');
      for i:=1 to k-1 do
        if (x.RealPart[i] < 10) then
            write(t,'00'+x.RealPart[i])
          else
            if (x.RealPart[i] < 100) then
              write(t,'0'+x.RealPart[i])
            else
              write(t,x.RealPart[i]);
      write(t,last_convert(x));
      writeln(t);
    end;
  
  {Сравнивание чисел}
  function Less (x,y:RealNumber): boolean;
  
    var
      b,c1,c2: boolean;
      i: byte;
      s: string;
      a: word;
  
    begin
      c1 := false;
      c1 :=false;
      b := false;
      if (x.IntPart[0] > y.IntPart[0]) then
        begin
          writeln(outf,'Первое число больше второго');
          Less := true;
        end
      else
        if (x.IntPart[0] < y.IntPart[0]) then
          begin
            writeln(outf,'Второе число больше первого');
            Less := false;
          end
        else
          begin
            i := x.IntPart[0];
            while ((not c1) and (not c2) and (i>=1)) do
              begin
                if (x.IntPart[i] > y.IntPart[i]) then
                  begin
                    c1 := true;
                    Less := true;
                    b := false;
                    writeln(outf,'Первое число больше второго');
                  end
                else
                  if (y.IntPart[i] > x.IntPart[i]) then
                    begin
                      c2 := true;
                      Less := false;
                      b := false;
                      writeln(outf,'Второе число больше первого');
                    end
                  else
                    b := true;
                i:=i-1;
              end;
          end;
      if (b) then
        begin
          if (x.RealPart[0] > y.RealPart[0]) then
            begin
              i:=1;
              while ((not c1) and (not c2) and (i <= y.RealPart[0])) do
                begin
                  if (i < y.RealPart[0]) then
                    begin
                      if (x.RealPart[i] > y.RealPart[i]) then
                        begin
                          c1 := true;
                          Less := true;
                          writeln(outf,'Первое число больше второго');
                        end
                      else
                        if (y.RealPart[i] > x.RealPart[i]) then
                          begin
                            c2 := true;
                            Less := false;
                            writeln(outf,'Второе число больше первого');
                          end;
                    end
                  else
                    begin
                      s := Last_convert(RealNumber2);
                      a := StrToInt(s);
                      if (a < x.RealPart[i]) then
                        begin
                          c1 := true;
                          Less := true;
                          writeln(outf,'Первое число больше второго');
                        end
                      else
                        if (a > x.RealPart[i]) then
                          begin
                            c2 := true;
                            Less := false;
                            writeln(outf,'Второе число больше первого');
                          end;
                    end;
                  i:=i+1;
                end;
              if ((not c1) and (not c2)) then
                begin
                  writeln(outf,'Первое число больше второго');
                  Less := true;
                end;
            end
          else
            if (x.RealPart[0] < y.RealPart[0]) then
              begin
                i:=1;
                while ((not c1) and (not c2) and (i <= x.RealPart[0])) do
                  begin
                    if (i < x.RealPart[0]) then
                      begin
                        if (x.RealPart[i] > y.RealPart[i]) then
                          begin
                            c1 := true;
                            Less := true;
                            writeln(outf,'Первое число больше второго');
                          end
                        else
                          if (y.RealPart[i] > x.RealPart[i]) then
                            begin
                              c2 := true;
                              Less := false;
                              writeln(outf,'Второе число больше первого');
                            end;
                      end
                    else
                      begin
                        s := Last_convert(RealNumber1);
                        a := StrToInt(s);
                        if (a > y.RealPart[i]) then
                          begin
                            c1 := true;
                            Less := true;
                            writeln(outf,'Первое число больше второго');
                          end
                        else
                          if (y.RealPart[i] > a) then
                            begin
                              c2 := true;
                              Less := false;
                              writeln(outf,'Второе число больше первого');
                            end;
                      end;
                    i:=i+1;
                  end;
                if ((not c1) and (not c2)) then
                  begin
                    writeln(outf,'Второе число больше первого');
                    Less := false;
                  end;
              end
                else
                  begin
                    i:=1;
                    while ((not c1) and (not c2) and (i <= x.RealPart[0])) do
                      begin
                        if (x.RealPart[i] > y.RealPart[i]) then
                          begin
                            c1 := true;
                            Less := true;
                            writeln(outf,'Первое число больше второго');
                          end
                        else
                          if (y.RealPart[i] > x.RealPart[i]) then
                            begin
                              c2 := true;
                              Less := false;
                              writeln(outf,'Второе число больше первого');
                            end;
                        i:=i+1;
                      end;
                    if ((not c1) and (not c2)) then
                      begin
                        writeln(outf,'Числа равны');
                        Less := true;
                      end;
                  end;
        end;
    end;
  
  {Вычитание из большего числа меньшее}
  procedure SubRealNumbers (x,y:RealNumber; var SubNumbers:RealNumber);
  
    var
      i:byte;
      d:boolean;
    
    {Вычитание двух цифр}
    function sub (x,y:integer; var z:integer; var d:boolean):boolean;
          
      begin
        if (d) then
          begin
            x := x-1;
          end;
        if (x < y) then
          begin
            x := x + m;
            sub := true;
            z := x - y;
          end
        else
          begin
            z := x-y;
            sub := false;
          end;
      end;
    
    {Вычтиние дробной части}
    function SubRealPart (x,y:RealNumber; var SubNumbers:RealNumber): boolean;
      
      var
        a,b,c,a1,b1,c1,sa,sb,sc,k,i,j:integer;
        d,p,v,f: boolean;
        
      begin
        d := false;
        f := true;
        v := true;
        if (x.RealPart[0] < y.RealPart[0]) then
          begin
            k := y.RealPart[0];
            SubNumbers.RealPart[0] := y.RealPart[0];
          end
        else
          begin
            k := x.RealPart[0];
            SubNumbers.RealPart[0] := x.RealPart[0];
          end;
        for i := k downto 1 do
          begin
            p := false;
            toRealParts(x,a,b,c,i);
            ToRealParts(y,a1,b1,c1,i);
            if (d) then
              begin
                if (c = 0) then
                  begin
                    c := m-1;
                    if (b = 0) then
                      begin
                        b := m-1;
                        if (a = 0) then
                          begin
                            a := m-1;
                          end
                        else
                          begin
                            a := a - 1;
                            d := false;
                          end;
                      end
                    else
                      begin
                        b := b - 1;
                        d := false;
                      end;
                  end
                else
                  begin
                    c := c - 1;
                    d := false;
                  end;
              end;
            p:=sub(c,c1,sc,p);
            p:=sub(b,b1,sb,p);
            if (d) then
              sub(a,a1,sa,p)
            else
              d:=sub(a,a1,sa,p);
            if not ((f) and ((100*sc + 10*sb + sa) = 0)) then
              begin
                f := false;
                if (v) then 
                  begin
                    SubNumbers.RealPart[i] := 100*sc + 10*sb + sa;
                    v := false;
                  end
                else
                  SubNumbers.RealPart[i] := 100*sa + 10*sb + sc;
              end;
            
          end;
        SubRealPart := d;
      end;
    
    {Вычитание Целой части}
    function SubIntPart (x,y:RealNumber; var SubNumbers:RealNumber; d: boolean): boolean;
      
      var
        a,b,c,a1,b1,c1,sa,sb,sc,k,i,j:integer;
        p: boolean;
        
      begin
        k := x.IntPart[0];
        SubNumbers.IntPart[0] := k;
        for i := 1 to k do
          begin
            p := false;
            toIntParts(x,a,b,c,i);
            toIntParts(y,a1,b1,c1,i);
            if (d) then
              begin
                if (c = 0) then
                  begin
                    c := m-1;
                    if (b = 0) then
                      begin
                        b := m-1;
                        if (a = 0) then
                          begin
                            a := m-1;
                          end
                        else
                          begin
                            a := a - 1;
                            d := false;
                          end;
                      end
                    else
                      begin
                        b := b -1;
                        d := false;
                      end;
                  end
                else
                  begin
                    c := c - 1;
                    d := false;
                  end;
              end;
            p:=sub(c,c1,sc,p);
            p:=sub(b,b1,sb,p);
            if (d) then
              sub(a,a1,sa,p)
            else
              d:=sub(a,a1,sa,p);
            SubNumbers.IntPart[i] := 100*sa + 10*sb + sc;
          end;
        
      end;
    
    begin
      d := SubRealPart(x,y,SubNumbers);
      SubIntPart(x,y,SubNumbers,d);
      i := SubNumbers.IntPart[0];
      while ((i > 1) and (SubNumbers.IntPart[i] = 0)) do // Отсечение незначащих нулей в целой части
        begin
          SubNumbers.IntPart[0] := SubNumbers.IntPart[0] - 1;
          i := i - 1;
        end;
      i := SubNumbers.RealPart[0];
      while ((i > 1) and (SubNumbers.RealPart[i] = 0)) do // Отсечение незначащих нулей в дробной части
        begin
          SubNumbers.RealPart[0] := SubNumbers.RealPart[0] - 1;
          i := i - 1;
        end;
    end;

  {Сложение чисел}  
  procedure SumRealNumbers (x,y: RealNumber; var SumNumbers: RealNumber);
    
    var 
      b: boolean;
      k,i,d,r,j,z: byte;
      f,s:word;
      
    {Сложение двух цифр}
    function sum (x,y:integer; var z:integer; var d:boolean):boolean;
          
      begin
        if (d) then
          begin
            x := x+1;
          end;
        z := x+y;
        if (z >= m) then
          begin
            sum := true;
            z := z - m; 
          end
        else
          sum := false;
      end;
  
  {Сложение дробных частей}
  function SumRealParts (x,y: RealNumber; var SumNumbers: RealNumber):boolean;
  
    var
        a,b,c,a1,b1,c1,sa,sb,sc,k,i,j:integer;
        d,p,v,f: boolean;
        
      begin
        d := false;
        f := true;
        v := true;
        if (x.RealPart[0] < y.RealPart[0]) then
          begin
            k := y.RealPart[0];
            SumNumbers.RealPart[0] := y.RealPart[0];
          end
        else
          begin
            k := x.RealPart[0];
            SumNumbers.RealPart[0] := x.RealPart[0];
          end;
        for i := k downto 1 do
          begin
            p := false;
            toRealParts(x,a,b,c,i);
            ToRealParts(y,a1,b1,c1,i);
            if (d) then
              begin
                if (c = m-1) then
                  begin
                    c := 0;
                    if (b = m-1) then
                      begin
                        b := 0;
                        if (a = m-1) then
                          begin
                            a := 0;
                          end
                        else
                          begin
                            a := a + 1;
                            d := false;
                          end;
                      end
                    else
                      begin
                        b := b + 1;
                        d := false;
                      end;
                  end
                else
                  begin
                    c := c + 1;
                    d := false;
                  end;
              end;
            p:=sum(c,c1,sc,p);
            p:=sum(b,b1,sb,p);
            if (d) then
              sum(a,a1,sa,p)
            else
              d:=sum(a,a1,sa,p);
            if not ((f) and ((100*sc + 10*sb + sa) = 0)) then
              begin
                f := false;
                if (v) then 
                  begin
                    SumNumbers.RealPart[i] := 100*sc + 10*sb + sa;
                    v := false;
                  end
                else
                  SumNumbers.RealPart[i] := 100*sa + 10*sb + sc;
              end;
            
          end;
        SumRealParts := d;
      end;
    
  begin
    b := SumRealParts (RealNumber1,RealNumber2,SumNumbers);
    if b then
      d:=1
    else
      d:=0;
    k := x.IntPart[0]+1;
    SumNumbers.IntPart[0] := k;
    for i := 1 to k do
      begin
        r := 1;
        f := x.IntPart[i]; 
        s := y.IntPart[i];
        for j := 1 to 3 do
          begin
            z := f mod 10 + s mod 10 + d;
            d := z div 8;
            SumNumbers.IntPart[i] := SumNumbers.IntPart[i] + (z mod 8)*r;
            r := r*10;
            f := f div 10; 
            s := s div 10;
          end;
      end;
    i := SumNumbers.IntPart[0];
    while ((i > 1) and (SumNumbers.IntPart[i] = 0)) do // Отсечение незначащих нулей в целой части
        begin
          SumNumbers.IntPart[0] := SumNumbers.IntPart[0] - 1;
          i := i - 1;
        end;
    i := SumNumbers.RealPart[0];
    while ((i > 1) and (SumNumbers.RealPart[i] = 0)) do // Отсечение незначащих нулей в дробной части
      begin
        SumNumbers.RealPart[0] := SumNumbers.RealPart[0] - 1;
        i := i - 1;
      end;
  end;

begin
  assign(inf,'input.txt');
  assign(outf, 'output.txt');
  reset(inf);
  rewrite(outf);
  if (ReadRealNumber(inf,RealNumber1)) then
    begin
      if (ReadRealNumber(inf,RealNumber2)) then
        begin
          WriteRealNumber(outf,RealNumber1);
          WriteRealNumber(outf,RealNumber2);
          if (Less(RealNumber1,RealNumber2)) then
            begin
              SubRealNumbers(RealNumber1,RealNumber2,SubNumbers);
              write(outf,'Разность чисел = ');
              WriteRealNumber(outf,SubNumbers);
              SumRealNumbers(RealNumber1,RealNumber2,SumNumbers);
              write(outf,'Сумма чисел = ');
              WriteRealNumber(outf,SumNumbers);
            end
          else
            begin
              SubRealNumbers(RealNumber2,RealNumber1,SubNumbers);
              write(outf,'Разность чисел = ');
              WriteRealNumber(outf,SubNumbers);
              SumRealNumbers(RealNumber2,RealNumber1,SumNumbers);
              write(outf,'Сумма чисел = ');
              WriteRealNumber(outf,SumNumbers);
            end;
          
        end
      else
        writeln(outf,'Второе число введено неправильно');
    end
  else
    writeln(outf,'Первое число введено неправильно');
  close(inf);
  close(outf);
end.