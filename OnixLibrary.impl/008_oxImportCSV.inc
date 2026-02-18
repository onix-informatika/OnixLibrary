procedure oxImportCSV(csv: array of TStringList; tableName: String; tableColumns: array of string; firstRow: integer = 0; recreateTable: boolean = true; cleanTable: boolean = true);
var createQuery: String;
    insertQuery: String;
    colIndex: Integer;
    rowIndex: Integer;
    tableColumn: String;
    rowValues: array of Variant;
begin
    if recreateTable and oxtableexists(tableName) then
    begin
        oxSQLExp('drop table ' + tableName);
    end;

    if not oxTableExists(tableName) then
    begin        
        createQuery := 'create table ' + tableName + ' (';
        for colIndex := 0 to High(tableColumns) do
        begin                
            tableColumn := tableColumns[colIndex];
            createQuery := createQuery + char(13) + '   [' + tableColumn + '] varchar(max) ';
            if colIndex < High(tableColumns) then
            begin
                createQuery := createQuery + ',';
            end;
        end;                                     
        createQuery := createQuery + char(13) + ');';
        oxSQLExp(createQuery);
    end;
    
    if cleanTable then
    begin
        oxSQLExp('truncate table ' + tableName);
    end; 

    insertQuery := 'insert into ' + tableName + '(';
          
    for colIndex := 0 to High(tableColumns) do
    begin
        insertQuery := insertQuery + '[' + tableColumns[colIndex] + ']';
        if colIndex < High(tableColumns) then
        begin
            insertQuery := insertQuery + ', ';
        end;
    end;
    
    insertQuery := insertQuery + ')' + char(13) + 'values(';
        
    for colIndex := 0 to High(tableColumns) do
    begin
        insertQuery := insertQuery + ':p' + IntToStr(colIndex); 
        if colIndex < High(tableColumns) then
        begin
            insertQuery := insertQuery + ',';
        end;
    end;        
                               
    insertQuery := insertQuery + ');'; 
    
    SetLength(RowValues, Length(tableColumns));
        
    for rowIndex := firstRow to High(csv) do
    begin              
        for colIndex := 0 to High(tableColumns) do
        begin             
            rowValues[colIndex] := csv[rowIndex][colIndex];
        end;                                    
        oxSQLExpWithParams(insertQuery, rowValues);
    end;
end;




