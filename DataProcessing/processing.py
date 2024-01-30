import pandas as pd
import seaborn as sns
from scipy.stats import shapiro
from sklearn.preprocessing import MinMaxScaler
import matplotlib.pyplot as plt

def correlation_matrix(normalized_data):
    """
    Построение и вывод матрицы корреляции для нормализованных данных.

    Parameters:
    normalized_data (pd.DataFrame): Нормализованные данные.

    Returns:
    None
    """
    correlation_matrix = normalized_data.corr()

    print("\nМатрица корреляции:")
    print(correlation_matrix)

    # Построение тепловой карты для матрицы корреляции
    plt.figure(figsize=(10, 8))
    sns.heatmap(correlation_matrix, annot=True, cmap='coolwarm', fmt=".2f")
    plt.title("Матрица корреляции")
    plt.show()

def histogram_of_features(normalized_data):
    """
    Построение и вывод гистограмм распределения для нормализованных данных.

    Parameters:
    normalized_data (pd.DataFrame): Нормализованные данные.

    Returns:
    None
    """
    normalized_data.hist(figsize=(12, 8))
    plt.suptitle("Гистограммы распределения")
    plt.show()

def pairplot_of_features(normalized_data):
    """
    Построение и вывод диаграммы рассеяния для нормализованных данных.

    Parameters:
    normalized_data (pd.DataFrame): Нормализованные данные.

    Returns:
    None
    """
    pairplot_data = normalized_data[['X3 distance to the nearest MRT station',
                                     'X4 number of convenience stores',
                                     'X5 latitude', 'X6 longitude',
                                     'Y house price of unit area']]
    sns.pairplot(pairplot_data)
    plt.suptitle('Парный график объектов')
    plt.show()

def processing_of_omissions(normalized_data):
    """
    Обработка пропусков в данных, заполнение средним значением.

    Parameters:
    normalized_data (pd.DataFrame): Нормализованные данные.

    Returns:
    None
    """
    normalized_data.fillna(normalized_data.mean(), inplace=True)

    print("Нормализованные данные:")
    print(normalized_data.head())

def search_for_interdependent_data(normalized_data):
    """
    Построение и вывод диаграммы рассеяния для поиска взаимозависимых данных.

    Parameters:
    normalized_data (pd.DataFrame): Нормализованные данные.

    Returns:
    None
    """
    sns.pairplot(normalized_data)
    plt.suptitle("Диаграммы рассеяния")
    plt.show()

def normality_test(normalized_data):
    """
    Тест на нормальность для каждой колонки в нормализованных данных.

    Parameters:
    normalized_data (pd.DataFrame): Нормализованные данные.

    Returns:
    None
    """
    print("\nТест на нормальность:")
    for column in normalized_data.columns:
        stat, p_value = shapiro(normalized_data[column])
        print(f'Колонка {column}: p-value = {p_value}')

        if p_value < 0.05:
            print(f"Отвергаем нулевую гипотезу о нормальности для колонки {column}")
        else:
            print(f"Не отвергаем нулевую гипотезу о нормальности для колонки {column}")

def data_normalization(data):
    """
    Нормализация данных в диапазоне [-1, 1].

    Parameters:
    data (pd.DataFrame): Исходные данные.

    Returns:
    pd.DataFrame: Нормализованные данные.
    """
    scaler = MinMaxScaler(feature_range=(-1, 1))
    normalized_data = pd.DataFrame(scaler.fit_transform(data), columns=data.columns)
    return normalized_data
