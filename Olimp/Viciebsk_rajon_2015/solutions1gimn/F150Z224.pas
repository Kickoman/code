var a:string;
    n,m,x,i:integer;
    f1,f2:text;
begin
 assign(f1,'input.txt');
 assign(f2,'output.txt');
 reset(f1);
 readln(f1,n,m);
 read(f1,a);
 rewrite(f2);
 for i:=1 to n do for x:=1 to m do write(f2,a[i+n*(x-1)]);
 close(f1);
 close(f2);
end.
