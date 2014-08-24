{R+,S+,Q+,I+,O-}
{$R-,S-,Q-,I-,O+}
const co = 10; md = 1234569; cnt = 20000000;
var
  tmp,qq,tt,n,i,j,it,hh: longint;
  ok: boolean;
  s1,s2: int64;
  q: array [0..555] of int64;
  s: array [0..cnt+10] of int64;
  pred: array [0..cnt+10] of longint;
  who: array [0..cnt+10,1..co] of word;
  was: array [0..555] of longint;
  last: array [0..md] of longint;
begin
  randseed:=8753;
  assign(input,'in'); reset(input);
  assign(output,'out'); rewrite(output);
  read(tt);
  for qq:=1 to tt do
  begin
    writeln('Case #',qq,':');
    read(n);
    for i:=1 to n do read(q[i]);
    fillchar(last,sizeof(last),0);
    for i:=1 to n do was[i]:=0;
    ok:=False;
    for it:=1 to cnt do
    begin
      s[it]:=0;
      for i:=1 to co do
      begin
        repeat
          j:=random(n)+1;
        until was[j] < it;
        was[j]:=it;
        s[it]:=s[it]+q[j];
        who[it,i]:=j;
      end;
      for i:=1 to co-1 do
        for j:=i+1 to co do
          if who[it,i] > who[it,j] then
          begin
            tmp:=who[it,i]; who[it,i]:=who[it,j]; who[it,j]:=tmp;
          end;
      hh:=s[it] mod md;
      j:=last[hh];
      while j > 0 do
      begin
        if s[j] = s[it] then
        begin
          for i:=1 to co do
            if who[j,i] <> who[it,i] then
            begin
              ok:=True;
              break;
            end;
          if ok then
          begin
            s1:=0; s2:=0;
            for i:=1 to co-1 do write(q[who[j,i]],' ');
            writeln(q[who[j,co]]);
            for i:=1 to co-1 do write(q[who[it,i]],' ');
            writeln(q[who[it,co]]);
            for i:=1 to co do s1:=s1+q[who[j,i]];
            for i:=1 to co do s2:=s2+q[who[it,i]];
            break;
          end;
        end;
        j:=pred[j];
      end;
      if ok then break;
      pred[it]:=last[hh];
      last[hh]:=it;
    end;
    if not ok then writeln('Impossible');
    flush(output);
  end;
  close(input);
  close(output);
end.