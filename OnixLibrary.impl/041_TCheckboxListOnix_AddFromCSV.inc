procedure TCheckboxListOnix.AddFromCSV(CSV: string);
var
  lines, fields: TStringList;
  i: Integer;
begin
  // split CSV into lines
  lines := TStringList.Create;
  lines.Text := CSV;

  fields := TStringList.Create;
  fields.Delimiter := ',';
  fields.StrictDelimiter := True; // spaces are not considered as delimiters

  for i := 0 to lines.Count - 1 do
  begin
    // split each line into fields
    fields.DelimitedText := lines[i];

    // assuming CSV contains no missing fields
    if fields.Count = 3 then
      self.Add(fields[0], fields[1], fields[2] = '1')
    else
      raise Exception.Create('Invalid CSV data');
  end;

  fields.Free;
  lines.Free;
end;




