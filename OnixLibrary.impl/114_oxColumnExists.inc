function oxColumnExists(tableName: String; columnName: String): boolean;
var alterSQL: String;
begin
    alterSQL := 'select top 1 1 from syscolumns where ID = OBJECT_ID(''' + tableName + ''') and NAME = ''' + columnName + ''';';
    Result := oxSQLExp(alterSQL) = '1';  
end;



