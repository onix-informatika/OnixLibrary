function GetFirstBusinessDayAfterToday: TDateTime;
var
  DateAfterToday: TDateTime;
begin
DateAfterToday := IncDay(DateOf(Now), 1);

  while IsWeekend(DateAfterToday) do
  begin
    DateAfterToday := IncDay(DateAfterToday, 1);
  end;
  Result := DateAfterToday;
end;




