function EnsureCountryCode(const Number: String; const DefaultCountryCode: String): String;
begin
  // Check if the number starts with '+' or '00' which means it's already in international format
  if Number.StartsWith('+') or Number.StartsWith('00') then
  begin
    Result := Number;
  end
  else
  begin
    // If the number starts with '0', remove this leading '0' before adding the country code
    if Number.StartsWith('0') then
    begin
      Result := DefaultCountryCode + Copy(Number, 2, MaxInt);
    end
    else
    begin
      Result := DefaultCountryCode + Number;
    end;
  end;
end;




