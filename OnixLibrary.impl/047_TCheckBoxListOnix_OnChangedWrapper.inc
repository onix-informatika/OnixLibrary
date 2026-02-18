procedure TCheckBoxListOnix.OnChangedWrapper(Sender: TObject);
begin
    if (skipCheckboxCallbacks <> true) and (assigned(OnChanged)) then OnChanged(Self);
end;




