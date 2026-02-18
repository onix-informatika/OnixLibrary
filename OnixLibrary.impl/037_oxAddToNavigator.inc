procedure oxAddToNavigator(field: String; fieldLen: Integer; fieldName: String; fieldF: String; navigator: String = 'bMenuDBNavigator'; atIndex: Integer = -1);
begin
    oxAddDefToNavigator(
        field + #9 + IntToStr(fieldLen) + #9 + fieldName + #9 + fieldF,
        navigator,
        atIndex
    );
end;




