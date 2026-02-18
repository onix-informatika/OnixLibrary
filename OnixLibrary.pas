unit OnixLibrary;

// verzija 1

interface 


Uses dlComponents, cxScrollBox, cxgrid, controls, Variants, dlDatabase, Sysutils, 
    cxCalc, Forms, dialogs, Classes, clEncoder, menus, DB, extctrls, DateUtils, clHTTP, 
    clHTTPRequest, clJson, dlCommon;

type TCheckboxListOnix = class(TComponent)
    private                 
        parent: TComponent;
        scrollBox: TcxScrollBox;
        popupMenu: TPopupMenu;
	    totalScrollboxHeight: Integer;
	    values: TStringList;
        skipCheckboxCallbacks: boolean; 
        procedure popupMenuPopup(Sender: TObject; MousePos: TPoint; var Handled: Boolean);
        procedure scrollboxMouseWheelDown(Sender: TObject; Shift: TShiftState; MousePos: TPoint; var Handled: Boolean);
        procedure scrollboxMouseWheelUp(Sender: TObject; Shift: TShiftState; MousePos: TPoint; var Handled: Boolean);
        procedure addMenuItems();
        procedure checkAllMenuItemClicked(Sender: TObject);
        procedure uncheckAllMenuItemClicked(Sender: TObject);
        procedure checkInverseMenuItemClicked(Sender: TObject); 
        procedure onChangedWrapper(Sender: TObject);
    public                
        onChanged: TNotifyEvent;
        constructor Create(AParent: TComponent); override;
        procedure Add(AKey: string; AValue: string; AChecked: boolean = false);
        procedure AddFromCSV(CSV: string);
        procedure AddFromDataSet(Dataset: TdlDataSet);
        function GetSelectedKeys():TStringList;
        function GetSelectedKeysJoined(by: String = ','):string;
        function GetSelectedKeysJoinedAndQuoted(by: String = ','):string;
    end;

type oxCallback = procedure();
 
type 
    TLocalAfterOpen = class(TObject)
    private                        
        oldEvent: TDataSetNotifyEvent;
    public                   
        AfterOldEvent: boolean;
        Callback: oxCallback;
        NewEvent: procedure(DataSet: TdlDataSet);
        constructor Create(oldEvent: TDataSetNotifyEvent);
    end;
    
type
    TcxDisplayTextOrdinalHelper = class(TObject)
    public 
        GetDisplayTextOrdinalNumber: procedure(Sender: TcxCustomGridTableItem; ARecord: TcxCustomGridRecord; var AText: String);
    end;
 
type
    TLocalAfterClick = class(TObject)
    private                        
        oldEvent: TNotifyEvent;
    public                   
        AfterOldEvent: boolean;
        Callback: oxCallback;
        NewEvent: procedure(Sender: TObject);
        constructor Create(oldEvent: TNotifyEvent);
    end;
 
type
    TLocalNotifyEvent = class(TObject)
    public
        Callback: oxCallback;
        procedure NotifyEvent(Sender: TObject);
        constructor Create(Callback: oxCallback);
    end;
    
type
    TDeferEvent = class(TObject)
    public
        Callback: oxCallback;
        Timer: TTimer;                           
        Timeout: Integer;
        procedure TimerFired(Sender: TObject);
        constructor Create(forCallback: oxCallback; forTimeout: Integer);
    end;

function oxSQLExp(SQL: String): String;
function oxSQLExpWithParams(SQL: String; params: array of Variant): String;
function oxSQLBlobToStream(sql: string; params: array of Variant): TStream;
function oxAddColumn(gridName: String; columnCaption: String; columnFieldName: String; width: integer = 50): TcxGridDBColumn;
function oxAddCurrencyColumn(gridName: String; columnCaption: String; columnFieldName: String; width: integer = 50): TcxGridDBColumn;
function oxAddNumericColumn(gridName: String; columnCaption: String; columnFieldName: String; width: integer = 50): TcxGridDBColumn;
function oxAddCheckboxColumn(gridName: String; columnCaption: String; columnFieldName: String; width: integer = 50): TcxGridDBColumn;
function oxGetGridSQL(gridName: String): String;
function oxGetDatasetSQL(dataSet: String): String;
function oxGetDataset(dataset: String): TdlDataSet;
function oxGetGrid(grid: String): TcxGridDBTableView;
function oxOnlyASCIILetterAndNumbers(s: String): String;
function oxNavigatorAcKey(name: String = 'bMenuDBNavigator'): String;
function oxGetValue(ofElement: String): String;
function oxAsAcKey(someText: String): String;
function oxAsFloat(someText: String): extended;
function oxAddOrdinalNumberColumn(grid: String; columnCaption: String = 'Rbr.'; columnFieldName: String = '_ordinal_column_internal_ox'; width: integer = 50): TcxGridDBColumn;
function oxGetButton(button: String): TcxButton;
function oxConfirmBool(what: String): Boolean;
function oxAddButtonInto(intoComponentName: String; inLineWithComponentName: String; caption: String; relativeCoordinates: array of Integer; onClickCallback: oxCallback): TdlcxButton;
function oxGetActiveFieldValue(gridOrDSName: string; fieldName: String): String;
function oxSTruthy(v: String; zeroIsFalsy: boolean = false): boolean;
function oxDTruthy(v: TDateTime): boolean;
function oxColumnExists(tableName: String; columnName: String): boolean;
Function oxTableExists(tableName: String): boolean;
function oxDateToSQLString(date: TDateTime): String;
function oxNavigator(name: String = 'bMenuDBNavigator'): TNavigator3;
function oxCheckComboBoxSelectedKeys(cbx: TcxCheckComboBox): TStringList;
function oxCheckComboBoxSelectedKeysSeparated(cbx: TcxCheckComboBox; delimiter: String = ','): String;
function oxSQLStepResult(stepId: Integer): String;
function oxSQLStepResultWithParams(stepId: Integer; params: array of Variant): String;
function oxSQLStepResultWithParamsAndBlob(stepId: Integer; blob: TStream; params: array of Variant): String;
function oxSQLStepRowResultWithParamsAndBlob(stepId: Integer; blob: TStream; params: array of Variant): TdlDataSet;
function oxSQLStepRowResultWithParams(stepId: Integer; params: array of Variant): TdlDataSet;
function oxSQLStepResultAnotherAres(stepId: Integer; aresAcKey: String): String;
function oxSQLStepResultWithParamsAnotherAres(stepId: Integer; aresAcKey: String; params: array of Variant): String;
function IsWeekend(ADate: TDateTime): Boolean;
function GetFirstBusinessDayAfterToday: TDateTime;
Function oxColumnByFieldName(TableView: TcxGridDBTableView; Const FieldName: String): TcxGridDBColumn;
Function oxColumnByName(TableView: TcxGridDBTableView; Const ColName: String): TcxGridDBColumn;
function oxSendTwilioMessage(const AccountSID, AuthToken, ToNumber, FromNumber, MessageBody: String): String;
function oxSendInfoBipMessage(const BaseURL, APIKey, Sender, Recipient, MessageText: String): String;
function oxSQLStepWithAresVariablesApplied(stepId: Integer): String;
function oxApplyAresVariablesToString(s: String): String;
function oxParseCSV(const CSVFileName, Delimiter, QuoteChar: string): array of TStringList;
function oxTransliterate(const Text: string): string;
function oxCommaTextToTStringList(commaText: String; delimiter: String = ','): TStringList;
function oxStreamToString(Stream: TStream): string;
function oxSQLExpRowWithParams(sql: string; params: array of Variant): TdlDataSet;
function oxContainsValue(const Arr: array of string; const Value: string): Boolean;
function oxMakeDSWithParams(sql: String; params: array of Variant): TdlDataSet;
function oxSQLExpWithBlob(sql: String; blob: TStream; params: array of Variant): String;
function oxSQLExpRowWithBlob(sql: String; blob: TStream; params: array of Variant): TdlDataSet;
function oxGetTempPath(): String;
function oxGetStepSQL(stepId: Integer): String;
function oxGetStepSQLFromAres(stepId: Integer; aresAcKey: String): String;
procedure oxLogAresVariables();
procedure oxDrillClassParent(obj: TObject); 
procedure oxDrillClassParentUpwards(obj: TWinControl); 
procedure oxAfterDataSetOpen(dataSet: String; callback: oxCallback; afterOldEvent: boolean = false);
procedure oxBeforeDataSetOpen(dataSet: String; callback: oxCallback; afterOldEvent: boolean = false);
procedure oxBeforeDataSetPost(dataSet: String; callback: oxCallback; afterOldEvent: boolean = false);
procedure oxAfterDataSetPost(dataSet: String; callback: oxCallback; afterOldEvent: boolean = false);
procedure oxAfterDataSetEdit(dataSet: String; callback: oxCallback; afterOldEvent: boolean = false);
procedure oxAfterDataSetDelete(dataSet: String; callback: oxCallback; afterOldEvent: boolean = false);
procedure oxRefreshDataset(dataSet: String);
procedure oxRefreshGrid(grid: String; keepRecord: boolean = false);
procedure oxRedrawGrid(grid: String);
procedure oxHackRefreshDataSet(dataSet: String);
procedure oxHackRefreshGrid(grid: String; callback: oxCallback);
procedure oxConfirm(what: String; onYes: oxCallback; onNo: oxCallback);
procedure oxForceColumnIndex(forColumn: TcxGridDBColumn; index: Integer);
procedure oxLogObjectClassname(o: TObject; oName: String = 'nepoznato');
procedure oxLogElementClassname(elementName: String);
procedure oxAddSQLColumn(tableName: String; columnName: String; sqlType: String);
procedure oxBeforeButtonClick(button: String; callback: oxCallback);
procedure oxOnButtonClick(button: String; callback: oxCallback);
procedure oxBeforePopupClick(popupName: String; callback: oxCallback);
procedure oxAfterButtonClick(button: String; callback: oxCallback);
procedure oxPrintComponent(component: TComponent; prefix: String = '');
procedure oxDataSetToCSV(DataSet: TdlDataSet; const FileName: string; const Delimiter: string = ';'; const QuoteEverything: boolean = false);
procedure oxAddToNavigator(field: String; fieldLen: Integer; fieldName: String; fieldF: String; navigator: String = 'bMenuDBNavigator'; atIndex: Integer = -1);
procedure oxAddToNavigatorAt(field: String; fieldLen: Integer; fieldName: String; fieldF: String; atIndex: Integer = -1);
procedure oxAddDefToNavigator(def: String; navigator: String = 'bMenuDBNavigator'; atIndex: Integer = -1);
procedure oxAddDefToNavigatorAt(def: String; atIndex: Integer = -1);
procedure oxDefer(callback: oxCallback; forMs: integer = 1);
procedure oxItemsFromDataset(cbx: TcxCheckComboBox; DataSet: TDataSet);
procedure oxImportCSV(csv: array of TStringList; tableName: String; tableColumns: array of string; firstRow: integer = 0; recreateTable: boolean = true; cleanTable: boolean = true);
procedure oxParseAndImportCSV(const CSVFileName, Delimiter, QuoteChar: string; tableName: String; tableColumns: array of string; firstRow: integer = 0; recreateTable: boolean = true; cleanTable: boolean = true);
procedure oxVersioned(stepId: integer; objectName: String; objectType: String; version: integer);

Implementation

{$I OnixLibrary.impl/001_oxGetTempPath.inc}
{$I OnixLibrary.impl/002_oxLogAresVariables.inc}
{$I OnixLibrary.impl/003_oxContainsValue.inc}
{$I OnixLibrary.impl/004_oxStreamToString.inc}
{$I OnixLibrary.impl/005_oxCommaTextToTStringList.inc}
{$I OnixLibrary.impl/006_oxTransliterate.inc}
{$I OnixLibrary.impl/007_oxParseCSV.inc}
{$I OnixLibrary.impl/008_oxImportCSV.inc}
{$I OnixLibrary.impl/009_oxParseAndImportCSV.inc}
{$I OnixLibrary.impl/010_oxSendTwilioMessage.inc}
{$I OnixLibrary.impl/011_oxSendInfoBipMessage.inc}
{$I OnixLibrary.impl/012_EnsureCountryCode.inc}
{$I OnixLibrary.impl/013_oxColumnByFieldName.inc}
{$I OnixLibrary.impl/014_oxColumnByName.inc}
{$I OnixLibrary.impl/015_oxCheckComboBoxSelectedKeys.inc}
{$I OnixLibrary.impl/016_oxCheckComboBoxSelectedKeysSeparated.inc}
{$I OnixLibrary.impl/017_oxItemsFromDataset.inc}
{$I OnixLibrary.impl/018_GetFirstBusinessDayAfterToday.inc}
{$I OnixLibrary.impl/019_IsWeekend.inc}
{$I OnixLibrary.impl/020_oxApplyAresVariablesToString.inc}
{$I OnixLibrary.impl/021_oxSQLStepWithAresVariablesApplied.inc}
{$I OnixLibrary.impl/022_oxSQLStepResultWithParamsAnotherAres.inc}
{$I OnixLibrary.impl/023_oxSQLStepResult.inc}
{$I OnixLibrary.impl/024_oxSQLStepResultWithParams.inc}
{$I OnixLibrary.impl/025_oxSQLStepRowResultWithParams.inc}
{$I OnixLibrary.impl/026_oxSQLStepResultWithParamsAndBlob.inc}
{$I OnixLibrary.impl/027_oxSQLStepRowResultWithParamsAndBlob.inc}
{$I OnixLibrary.impl/028_oxSQLStepResultAnotherAres.inc}
{$I OnixLibrary.impl/029_oxGetStepSQLFromAres.inc}
{$I OnixLibrary.impl/030_oxGetStepSQL.inc}
{$I OnixLibrary.impl/031_oxDefer.inc}
{$I OnixLibrary.impl/032_TDeferEvent_Create.inc}
{$I OnixLibrary.impl/033_TDeferEvent_TimerFired.inc}
{$I OnixLibrary.impl/034_TCheckboxListOnix_Create.inc}
{$I OnixLibrary.impl/035_oxAddToNavigatorAt.inc}
{$I OnixLibrary.impl/036_oxAddDefToNavigatorAt.inc}
{$I OnixLibrary.impl/037_oxAddToNavigator.inc}
{$I OnixLibrary.impl/038_oxAddDefToNavigator.inc}
{$I OnixLibrary.impl/039_oxDataSetToCSV.inc}
{$I OnixLibrary.impl/040_TCheckboxListOnix_addMenuItems.inc}
{$I OnixLibrary.impl/041_TCheckboxListOnix_AddFromCSV.inc}
{$I OnixLibrary.impl/042_TCheckboxListOnix_AddFromDataSet.inc}
{$I OnixLibrary.impl/043_TCheckboxListOnix_checkAllMenuItemClicked.inc}
{$I OnixLibrary.impl/044_TCheckboxListOnix_uncheckAllMenuItemClicked.inc}
{$I OnixLibrary.impl/045_TCheckboxListOnix_checkInverseMenuItemClicked.inc}
{$I OnixLibrary.impl/046_TCheckboxListOnix_Add.inc}
{$I OnixLibrary.impl/047_TCheckBoxListOnix_OnChangedWrapper.inc}
{$I OnixLibrary.impl/048_TCheckboxListOnix_popupMenuPopup.inc}
{$I OnixLibrary.impl/049_TCheckboxListOnix_scrollboxMouseWheelDown.inc}
{$I OnixLibrary.impl/050_TCheckboxListOnix_scrollboxMouseWheelUp.inc}
{$I OnixLibrary.impl/051_TCheckboxListOnix_GetSelectedKeys.inc}
{$I OnixLibrary.impl/052_TCheckboxListOnix_GetSelectedKeysJoined.inc}
{$I OnixLibrary.impl/053_TCheckboxListOnix_GetSelectedKeysJoinedAndQuoted.inc}
{$I OnixLibrary.impl/054_oxDrillClassParent.inc}
{$I OnixLibrary.impl/055_oxDrillClassParentUpwards.inc}
{$I OnixLibrary.impl/056_oxDateToSQLString.inc}
{$I OnixLibrary.impl/057_oxSQLExp.inc}
{$I OnixLibrary.impl/058_oxSQLExpRowWithBlob.inc}
{$I OnixLibrary.impl/059_oxSQLExpWithBlob.inc}
{$I OnixLibrary.impl/060_oxMakeDSWithParams.inc}
{$I OnixLibrary.impl/061_oxSQLExpRowWithParams.inc}
{$I OnixLibrary.impl/062_oxSQLExpWithParams.inc}
{$I OnixLibrary.impl/063_oxSQLBlobToStream.inc}
{$I OnixLibrary.impl/064_oxAddColumn.inc}
{$I OnixLibrary.impl/065_oxAddCurrencyColumn.inc}
{$I OnixLibrary.impl/066_oxAddNumericColumn.inc}
{$I OnixLibrary.impl/067_oxAddCheckboxColumn.inc}
{$I OnixLibrary.impl/068_oxGetGridSQL.inc}
{$I OnixLibrary.impl/069_oxGetDatasetSQL.inc}
{$I OnixLibrary.impl/070_oxGetDataset.inc}
{$I OnixLibrary.impl/071_oxOnlyASCIILetterAndNumbers.inc}
{$I OnixLibrary.impl/072_TLocalAfterOpen_Create.inc}
{$I OnixLibrary.impl/073_TLocalAfterOpen_NewEvent.inc}
{$I OnixLibrary.impl/074_oxAfterDataSetOpen.inc}
{$I OnixLibrary.impl/075_oxBeforeDataSetOpen.inc}
{$I OnixLibrary.impl/076_oxBeforeDataSetPost.inc}
{$I OnixLibrary.impl/077_oxRefreshDataset.inc}
{$I OnixLibrary.impl/078_oxAfterDataSetPost.inc}
{$I OnixLibrary.impl/079_oxAfterDataSetEdit.inc}
{$I OnixLibrary.impl/080_oxAfterDataSetDelete.inc}
{$I OnixLibrary.impl/081_oxGetGrid.inc}
{$I OnixLibrary.impl/082_oxRedrawGrid.inc}
{$I OnixLibrary.impl/083_oxRefreshGrid.inc}
{$I OnixLibrary.impl/084_oxHackRefreshDataSet.inc}
{$I OnixLibrary.impl/085_oxHackRefreshGrid.inc}
{$I OnixLibrary.impl/086_oxConfirm.inc}
{$I OnixLibrary.impl/087_oxConfirmBool.inc}
{$I OnixLibrary.impl/088_oxNavigator.inc}
{$I OnixLibrary.impl/089_oxNavigatorAcKey.inc}
{$I OnixLibrary.impl/090_oxGetValue.inc}
{$I OnixLibrary.impl/091_oxAsAcKey.inc}
{$I OnixLibrary.impl/092_oxAsFloat.inc}
{$I OnixLibrary.impl/093_TcxDisplayTextOrdinalHelper_GetDisplayTextOrdinalNumber.inc}
{$I OnixLibrary.impl/094_oxAddOrdinalNumberColumn.inc}
{$I OnixLibrary.impl/095_oxForceColumnIndex.inc}
{$I OnixLibrary.impl/096_oxLogObjectClassname.inc}
{$I OnixLibrary.impl/097_oxLogElementClassname.inc}
{$I OnixLibrary.impl/098_oxGetButton.inc}
{$I OnixLibrary.impl/099_oxGetPopup.inc}
{$I OnixLibrary.impl/100_TLocalAfterClick_Create.inc}
{$I OnixLibrary.impl/101_TLocalAfterClick_NewEvent.inc}
{$I OnixLibrary.impl/102_oxAddSQLColumn.inc}
{$I OnixLibrary.impl/103_oxBeforeButtonClick.inc}
{$I OnixLibrary.impl/104_oxBeforePopupClick.inc}
{$I OnixLibrary.impl/105_oxAfterButtonClick.inc}
{$I OnixLibrary.impl/106_oxOnButtonClick.inc}
{$I OnixLibrary.impl/107_oxGetActiveFieldValue.inc}
{$I OnixLibrary.impl/108_oxPrintComponent.inc}
{$I OnixLibrary.impl/109_TLocalNotifyEvent_Create.inc}
{$I OnixLibrary.impl/110_TLocalNotifyEvent_NotifyEvent.inc}
{$I OnixLibrary.impl/111_oxAddButtonInto.inc}
{$I OnixLibrary.impl/112_oxSTruthy.inc}
{$I OnixLibrary.impl/113_oxDTruthy.inc}
{$I OnixLibrary.impl/114_oxColumnExists.inc}
{$I OnixLibrary.impl/115_oxTableExists.inc}
{$I OnixLibrary.impl/116_Versioned.inc}
{$I OnixLibrary.impl/117_oxVersioned.inc}

end.
