function oxAddButtonInto(intoComponentName: String; inLineWithComponentName: String; caption: String; relativeCoordinates: array of Integer; onClickCallback: oxCallback): TdlcxButton;
var intoComponent: TdlcxPanel;
    inLineWithComponent: TControl;
    callbackWrapper: TLocalNotifyEvent;
    topOffset: Integer;
    leftOffset: Integer;
begin
    Result := TdlcxButton.Create(Ares);
    
    intoComponent := TdlcxPanel(AresFindComponent(intoComponentName, OwnerForm));
    inLineWithComponent := TControl(AresFindComponent(inLineWithComponentName, OwnerForm));
    
    callbackWrapper := TLocalNotifyEvent.Create(onClickCallback);
    
    if (Length(relativeCoordinates) = 0) then
    begin
        relativeCoordinates := [0, 0];
    end;
        
    if (Length(relativeCoordinates) = 2) then
    begin    
        topOffset := relativeCoordinates[0];
        leftOffset := relativeCoordinates[1];
        Result.Parent := intoComponent;
        Result.Top := inLineWithComponent.Top + topOffset;
        Result.Left := inLineWithComponent.Left + inLineWithComponent.Width + leftOffset;
        Result.Name := intoComponentName + inLineWithComponentName + oxOnlyASCIILetterAndNumbers(caption);
        Result.Enabled := true;
        Result.OnClick := callbackWrapper.NotifyEvent;
        Result.Caption := caption;
    end else
    begin
        showmessage('Unesite ispravan broj argumenata za relativne koordinate gumba u ' + intoComponentName + '. prazno [] ili [10, 0] odnosno [top, left] unutar ' + intoComponentName);
    end;
end;





