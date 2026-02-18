procedure oxAddSQLColumn(tableName: String; columnName: String; sqlType: String);
var alterSQL: String;
begin
    alterSQL := 'IF NOT EXISTS (SELECT * FROM syscolumns                 '             +
        'WHERE ID=OBJECT_ID(''' + tableName + ''') AND NAME=''' + columnName + ''')    '       +
        'ALTER TABLE ' + tableName + '      '                                          +
        'ADD ' + columnName + ' ' + sqlType + '';
    oxSQLExp(alterSQL);
end;




