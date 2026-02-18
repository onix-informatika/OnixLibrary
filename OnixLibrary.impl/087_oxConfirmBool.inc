function oxConfirmBool(what: String): Boolean;
var res: Integer;
begin
    result := false;
    _macro.eventlogadd('Executing dialog');
    try
        res := Integer(Dialogs.MessageDlg(what, mtConfirmation, [mbYes, mbNo], 0, mbYes));
        if (res = mrYes) then
        begin       
            _macro.eventlogadd('Executing yes');
            result := true;
        end;
        if (res = mrNo) then 
        begin       
            _macro.eventlogadd('Executing no');
        end;
    except on E: Exception do
        _macro.eventlogadd('Dialog error: ' + E.Message);
    end;
end;




