var  s:ansistring;
     k,j,i,n,m,f:longint;
begin
assign(input,'input.txt');reset(input);
assign(output,'output.txt');rewrite(output);
    readln(n,m);
    read(s);
    k:=1;
    f:=length(s) div m;
    //writeln(f);
    for i:=1 to f do
    begin
      write(s[i]);
      k:=i;
     for j:=1 to m-1 do
      begin
           write(s[k+n]);
          k:=k+n;
      end;
    end;
end.
