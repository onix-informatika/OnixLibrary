procedure oxAddToNavigatorAt(field: String; fieldLen: Integer; fieldName: String; fieldF: String; atIndex: Integer = -1);
begin
    oxAddToNavigator(field, fieldLen, fieldName, fieldF, 'bMenuDBNavigator', atIndex);
end;




