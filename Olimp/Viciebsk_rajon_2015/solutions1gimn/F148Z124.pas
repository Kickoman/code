var s1,s2:string;
    a:array[1..10001]of longint;
    n,i,f,k,x,sum,max,k1,c:longint;
function min(x,y:longint):longint;
begin
    if x<y then min:=x
    else
       min:=y;
end;
begin
assign(input,'input.txt');reset(input);
assign(output,'output.txt');rewrite(output);
    read(n);
    c:=0;
    s1:='YES';
    s2:='NO';
    f:=0;
    k1:=0;
    sum:=0;
    k:=0;
    for i:=1 to n do
     begin
         read(a[i]);
         sum:=sum+a[i];
     end;
    if (sum mod n=0) then writeln(s1)
     else
      begin
          writeln(s2);
          f:=1;
      end;
    if f=0 then
     begin
        for i:=1 to n do
          begin
              if a[i]<(sum div n) then
               begin
                  x:=(sum div n)-a[i];
                  k:=k+x;
               end;
          end;
        writeln(k);
     end
    else
       begin
          max:=0;
           for i:=1 to n do
            if a[i]>max then max:=a[i];
           for i:=1 to n do
            if a[i]<max then k:=(max-a[i])+k;
            c:=sum;
          while (sum mod n<>0) do
              sum:=sum+1;
          k1:=sum-c;
         writeln(min(k,k1));
       end;

end.
