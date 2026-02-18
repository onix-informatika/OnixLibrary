function IsWeekend(ADate: TDateTime): Boolean;
var
  DayOfWeek: Integer;
begin
  DayOfWeek := DayOfTheWeek(ADate);
  Result := (DayOfWeek = DaySaturday) or (DayOfWeek = DaySunday);
end;




