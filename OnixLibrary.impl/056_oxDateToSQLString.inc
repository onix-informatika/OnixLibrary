function oxDateToSQLString(date: TDateTime): String;
begin
    Result := FormatDateTime('yyyy-mm-dd"T"hh:nn:ss', date);
end;

// sqlexp(query)



