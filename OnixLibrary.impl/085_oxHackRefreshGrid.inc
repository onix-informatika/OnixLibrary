procedure oxHackRefreshGrid(grid: String; callback: oxCallback);
var colIndex: Integer;
    gridMode: boolean;
    columnSettings: TStringList;
    currSetting: String;
begin 
    columnSettings := TStringList.Create();
    with oxGetGrid(grid) do
    begin           
        for colIndex := 0 to ColumnCount - 1 do
        begin
            try
                with Columns[colIndex] do
                begin                 
                    currSetting := '';
                    columnSettings.Add(currSetting);
                    if Editing then currSetting := currSetting + 'T'
                    else currSetting := currSetting + 'F';
                    if Options.Editing then currSetting := currSetting + 'T'
                    else currSetting := currSetting + 'F';
                    if Properties.Readonly then currSetting := currSetting + 'T'
                    else currSetting := currSetting + 'F';
                    Editing := true;
                    Options.Editing := true;
                    Properties.Readonly := false;
                end;
            except on E: Exception do 
                _macro.EventLogAdd(E.message);
            end;
        end;    
        with DataController do
        begin       
            BeginUpdate;     
            Refresh;
            DataSet.Refresh;
            gridMode := DataModeController.GridMode;
            DataModeController.GridMode := not gridMode;
            EndUpdate;
        end;   
        callback();
        with DataController do
        begin       
            BeginUpdate;     
            Refresh;
            DataSet.Refresh;
            DataModeController.GridMode := gridMode;
            EndUpdate;
        end;
        for colIndex := 0 to ColumnCount - 1 do
        begin
            try
                with Columns[colIndex] do
                begin
                    Editing := columnSettings[colIndex][0] = 'T';
                    Options.Editing := columnSettings[colIndex][1] = 'T';
                    Properties.Readonly := columnSettings[colIndex][2] = 'T';
                end;
            except on E: Exception do 
                _macro.EventLogAdd(E.message);
            end;
        end;
    end;
end;




