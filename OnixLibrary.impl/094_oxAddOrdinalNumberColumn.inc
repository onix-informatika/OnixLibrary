function oxAddOrdinalNumberColumn(grid: String; columnCaption: String = 'Rbr.'; columnFieldName: String = '_ordinal_column_internal_ox'; width: integer = 50): TcxGridDBColumn;
var helper: TcxDisplayTextOrdinalHelper;
begin
    helper := TcxDisplayTextOrdinalHelper.Create();
    Result := oxAddColumn(grid, columnCaption, columnFieldName);
    with Result do
    begin                   
        OnGetDisplayText := helper.GetDisplayTextOrdinalNumber;
    end;
end;




