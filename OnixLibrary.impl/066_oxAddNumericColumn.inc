// cxgrid, cxcalc
function oxAddNumericColumn(gridName: String; columnCaption: String; columnFieldName: String; width: integer = 50): TcxGridDBColumn;
begin
	Result := oxAddColumn(gridName, columnCaption, columnFieldName, width);
    with Result do
    begin
        PropertiesClass := TcxCalcEditProperties;
        with TcxCalcEditProperties(Properties) do
        begin
            DisplayFormat := '###,##0.00';
        end;
    end;
end;




