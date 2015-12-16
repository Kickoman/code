var a:array[1..2005,1..2005]of longint;N,M,i,j,k,s,pi,pj,f,prov,fin:longint;
Begin
  assign(input,'Input.txt');
  assign(output,'Output.txt');
  reset(input);
  rewrite(output);
  readln(N,M);
  for i:=1 to N do
    for j:=1 to M do
     begin 
      read(a[i,j]);
      if a[i,j]=0 then k:=k+1; 
     end;
  
 s:=2;
 pi:=1;
 pj:=1;
 while s*s<=N*M do
  begin 
   fin:=0;
   f:=0;
   prov:=0;
   if (pi+s-1<=N)and(pj+s-1<=M)then
    for i:=pi to pi+s-1 do
      begin 
        for j:=pj to pj+s-1 do
         if a[i,j]=1 then 
           begin 
            f:=1;
            break;
           end;
         if f=1 then break;
         prov:=1;
      end; 
   if (f=0)and(prov=1) then k:=k+1;
   if pj<M then pj:=pj+1;
   
   if (pj=M)and(pi=N) then
     begin
       pi:=1;
       pj:=1;
       fin:=1;
     end;
   if (pj=M)and(fin=0)then 
    begin  
      pj:=1;
      pi:=pi+1;
    end;
   if fin=1 then s:=s+1;
  end;
  write(k); 
  close(input);
  close(output);
End.