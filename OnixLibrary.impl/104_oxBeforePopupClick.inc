procedure oxBeforePopupClick(popupName: String; callback: oxCallback);
var localBeforeClick: TLocalAfterClick;
begin
    with oxGetPopup(popupName) do
    begin
        localBeforeClick := TLocalAfterClick.Create(OnPopup);
        localBeforeClick.Callback := callback;
        localBeforeClick.AfterOldEvent := false;    
        OnPopup := localBeforeClick.NewEvent;
        _macro.eventlogadd('New event set before, for ' + popupName);
    end;
end;




