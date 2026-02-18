Function oxTableExists(tableName: String): boolean;
Var 
  alterSQL: String;
Begin
  alterSQL := 'SELECT CASE WHEN ' +
        '(LEFT(:p0, 1) = ''#'' and object_id(''tempdb..'' + :p0) is not null) ' +
        'OR ' +
        '(LEFT(:p0, 1) <> ''#'' AND EXISTS (SELECT 1 FROM sys.tables WHERE name = :p0)) ' +
        'THEN 1 ELSE 0 END ';

  Result := oxSQLExpWithParams(alterSQL, [tableName]) = '1';
End;





