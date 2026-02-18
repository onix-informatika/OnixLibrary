function oxSQLStepRowResultWithParamsAndBlob(stepId: Integer; blob: TStream; params: array of Variant): TdlDataSet;
var stepSQL: String;
begin
    stepSQL := oxGetStepSQLFromAres(stepId, Ares.AcKey);
    result := oxSQLExpRowWithBlob(stepSQL, blob, params);
end;




