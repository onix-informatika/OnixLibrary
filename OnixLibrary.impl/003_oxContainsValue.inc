function oxContainsValue(const Arr: array of string; const Value: string): Boolean;
var
  I: Integer;
begin
  Result := False;
  for I := 0 to High(Arr) do
    if Arr[I] = Value then
    begin
      Result := True;
      Exit;
    end;
end;




