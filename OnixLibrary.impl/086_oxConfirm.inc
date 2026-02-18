procedure oxConfirm(what: String; onYes: oxCallback = null; onNo: oxCallback = null);
var res: Integer;
begin
    _macro.eventlogadd('Executing dialog');
    try
        res := Integer(Dialogs.MessageDlg(what, mtConfirmation, [mbYes, mbNo], 0, mbYes));
        if (res = mrYes) then
        begin       
            _macro.eventlogadd('Executing yes');
            onYes();
        end;
        if (res = mrNo) then 
        begin       
            _macro.eventlogadd('Executing no');
            onNo();
        end;
    except on E: Exception do
        _macro.eventlogadd('Dialog error: ' + E.Message);
    end;
end;




