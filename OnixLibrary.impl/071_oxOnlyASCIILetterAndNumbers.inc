function oxOnlyASCIILetterAndNumbers(s: String): String;
var
  i, Count: Integer;
begin
  SetLength(Result, Length(s));
  Count := 0;
  for i := 1 to Length(s) do begin
    if (((s[i] >= #48) and (s[i] <= #57)) or ((s[i] >= #65) and (s[i] <= #90)) or ((s[i] >= #97) and (s[i] <= #122))) then 
    begin
      inc(Count);
      Result[Count] := s[i];
    end;
  end;
  SetLength(Result, Count);
end;

// sve za afterDataSetOpen




