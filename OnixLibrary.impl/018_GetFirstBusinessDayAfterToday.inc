// dateutils
function IsWeekend(ADate: TDateTime): Boolean;
var
  DayOfWeek: Integer;
begin
  DayOfWeek := DayOfTheWeek(ADate);
  Result := (DayOfWeek = DaySaturday) or (DayOfWeek = DaySunday);
end;

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




