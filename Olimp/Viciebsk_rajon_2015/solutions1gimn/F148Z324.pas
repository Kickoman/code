var a:array[1..3000,1..3000]of longint;
    n,m,i,j,k:longint;
begin
assign(input,'input.txt');reset(input);
assign(output,'output.txt');rewrite(output);
    read(n,m);
    for i:=1 to n do
     for j:=1 to m do
      read(a[i,j]);
    for i:=1 to n-1 do
     k:=k+((n*m) div i);
    k:=k+(((n*m)div n)div 2);
    for i:=1 to n do
     for j:=1 to m do
      if a[i,j]=1 then
       k:=k-n;
    if k<0 then
     begin
         writeln(0);
         halt;
     end;
   if n=m then
    writeln(k)
   else writeln(k-m);
end.