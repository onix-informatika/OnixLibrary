function oxGetGrid(grid: String): TcxGridDBTableView;
var c: TComponent;
begin
    c := AresFindComponent(grid, OwnerForm);
    
    if c is TcxGrid then
    begin
        Result := TcxGridDBTableView(TcxGrid(c).Views[0]);
    end 
    else if c is TcxGridDBTableView then
    begin
        Result := TcxGridDBTableView(c);
    end 
    else if c is TcxGridDBBandedTableView then
    begin
        Result := c;
    end
    else
    begin       
        _macro.EventLogAdd('Was of type: ' + c.ClassName);
        showmessage('Not a valid grid or gridview: ' + grid);
    end;
end;




