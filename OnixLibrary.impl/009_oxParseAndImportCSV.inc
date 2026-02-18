procedure oxParseAndImportCSV(const CSVFileName, Delimiter, QuoteChar: string; tableName: String; tableColumns: array of string; firstRow: integer = 0; recreateTable: boolean = true; cleanTable: boolean = true);
var parsed: array of TStringList;
begin
    parsed := oxParseCSV(CSVFileName, Delimiter, QuoteChar);
    oxImportCSV(parsed, tableName, tableColumns, firstRow, recreateTable, cleanTable);
end;




