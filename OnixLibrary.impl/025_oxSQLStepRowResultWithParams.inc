function oxSQLStepRowResultWithParams(stepId: Integer; params: array of Variant): TdlDataSet;
var stepSQL: String;
begin
    stepSQL := oxGetStepSQLFromAres(stepId, Ares.AcKey);
    result := oxSQLExpRowWithParams(stepSQL, params);
end;




