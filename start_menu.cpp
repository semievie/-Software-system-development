#include "input.h"
#include "lab_info.h"
#include "file_work.h"
#include "main_algorithms.h"
#include "merge_sort.h"
#include "merge_sort_tests.h"

void startProgram(void) {
    int user_choice{}; // Переменная для хранения выбора пользователя

    for (;;) {
        std::vector<std::vector<int>> arrays{};          // Вектор векторов для сортировки
        std::vector<std::vector<int>> original_arrays{}; // Копия исходных массивов
        std::string file_path{};
        size_t number_of_arrays{};

        // Меню выбора источника данных
        showInputMenu();
        runMergeSortTests();

        switch (user_choice = getKey(FILE_INPUT, RANDOM_INPUT)) {
        case FILE_INPUT:
            file_path = checkFile();
            getArraysFromFile(arrays, file_path);
            break;

        case RANDOM_INPUT:
            std::cout << "Введите количество массивов: ";
            number_of_arrays = getPosInt();
            generateRandomArrays(arrays, number_of_arrays);
            break;

        case QUIT:
            exit(EXIT_SUCCESS);
        }

        // Сохраняем исходные массивы
        original_arrays = arrays;

        std::cout << std::endl << "Сгенерированные массивы: " << std::endl;
        showArrays(arrays);

        // Сортировка
        startSorting(arrays);
        std::cout << "Отсортированные массивы: " << std::endl;
        showArrays(arrays);
        // Меню вывода/сохранения
        while (user_choice != QUIT) {
            showOutputMenu();

            switch (user_choice = getKey(SAVE, SAVE_SORT)) {
            case SAVE:
                 saveToFile(original_arrays);
                 std::cout << "Исходные массивы сохранены." << std::endl;
                
                break;
            case SAVE_SORT:
                saveToFile(arrays);
                std::cout << "Отсортированные массивы сохранены." << std::endl;
                break;
            
            case QUIT:
                break;
            }
        }

        std::cout << "1 - Перезапустить программу, ESC - Завершить работу программы." << std::endl;
        user_choice = getKey(RESET, RESET);

        if (user_choice == QUIT) {
            exit(EXIT_SUCCESS);
        }
    }
}

