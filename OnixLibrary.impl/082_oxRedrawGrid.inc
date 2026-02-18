procedure oxRedrawGrid(grid: String);
begin
    with oxGetGrid(grid) do
    begin
        DataController.UpdateItems(true);
    end;
end;




