function oxParseCSV(const CSVFileName, Delimiter, QuoteChar: string): array of TStringList;
var
  CSVFile: TStringList;
  I: Integer;
begin
  CSVFile := TStringList.Create;

  try
    // Load the CSV file
    CSVFile.LoadFromFile(CSVFileName);

    // Set the length of the result array
    SetLength(Result, CSVFile.Count);

    // Iterate over the lines in the CSV file
    for I := 0 to CSVFile.Count - 1 do
    begin
      Result[I] := TStringList.Create;

      // Set the delimiter and quote char
      Result[I].Delimiter := Delimiter;
      Result[I].StrictDelimiter := True; // Ignore spaces as delimiters
      Result[I].QuoteChar := QuoteChar;

      // Parse the line into a TStringList of fields
      Result[I].DelimitedText := CSVFile[I];
    end;
  finally
    CSVFile.Free;
  end;
end;




