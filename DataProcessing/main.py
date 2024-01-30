import pandas as pd
import processing as proc

data = pd.read_excel('data_1.xlsx')

normalized_data = proc.data_normalization(data)

proc.processing_of_omissions(normalized_data)

proc.correlation_matrix(normalized_data)

proc.histogram_of_features(normalized_data)

proc.search_for_interdependent_data(normalized_data)

proc.normality_test(normalized_data)
