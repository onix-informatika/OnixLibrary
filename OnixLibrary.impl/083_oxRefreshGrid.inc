procedure oxRefreshGrid(grid: String; keepRecord: boolean = false);
var
  DetailRecIdx : integer;
  MasterRecIdx : integer;
begin       
    MasterRecIdx := -1;
    DetailRecIdx := -1;
    with oxGetGrid(grid) do
    begin             
        if not keepRecord then
        begin
            DataController.RefreshExternalData();
            DataController.UpdateItems(true);
        end else 
        begin   
            if IsDetail then
            begin
                MasterRecIdx := MasterRecordIndex;
                DetailRecIdx := Controller.FocusedRecordIndex;
            end else 
            begin
                DetailRecIdx := Controller.FocusedRecordIndex;
            end;    
            DataController.RefreshExternalData();
            DataController.UpdateItems(true);
            _macro.eventlogadd('MasterRecIdx: ' + MasterRecIdx.ToString()); 
            _macro.eventlogadd('DetailRecIdx: ' + DetailRecIdx.ToString()); 
            if IsMaster and (MasterRecIdx > -1) then
            begin         
                _macro.eventlogadd('Is master and has focusable index');
                if Controller.FocusNextRecord(MasterRecIdx, true, true, true, false) then
                begin
                    ViewData.Rows[MasterRecIdx].Expand(false);
                    if IsDetail and (DetailRecIdx > -1) then
                    begin
                        Controller.FocusedRecordIndex := DetailRecIdx;
                    end;
                end;  
            end else
            begin
                if DetailRecIdx > -1 then
                begin                 
                    _macro.eventlogadd('nije master, stavljam focus na detail poziciju');
                    Controller.FocusNextRecord(DetailRecIdx, true, true, true, false);
                    ViewData.Rows[DetailRecIdx].Expand(false);
                    Controller.FocusedRecordIndex := DetailRecIdx;
                end else if MasterRecIdx > -1 then
                begin        
                    _macro.eventlogadd('nije detail, stavljam focus na master poziciju');
                    Controller.FocusNextRecord(MasterRecIdx, true, true, true, false);
                    ViewData.Rows[MasterRecIdx].Expand(false); 
                    Controller.FocusedRecordIndex := MasterRecIdx;
                end;
            end;
        end;
    end;
end;




