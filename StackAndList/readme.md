### Classes
Кравченя Андрей КНМО-101

Задание 1. Дана инфиксная запись арифметического выражения со скобками. 
Например, (2+1)x3+5. Нужно перевести эту запись в постфиксную (21+3x5+), 
после чего вычислить выражение.

Задание 2. Напишите реализацию очереди

Задание 3. Версионный стек. Поддерживаются операции Push, Pop, Rollback. 
Состояния стека после выполнения этих операций нумеруются. 
С помощью Rollback можно откатиться на любое состояние, указав его номер. 
Rollback тоже можно откатить. Помимо этого, существует операция Forget, позволяющая забыть всю историю изменений. 
После Forget нумерация операций начинается с начала, Forget нельзя откатить. 
Указать сложность каждого метода.

Задание 4. Дана случайная перестановка чисел от 1 до n. Пишем их на камнях и укладываем на песок в кольцо по часовой стрелке. Считаем текущим камнем первый в перестановке. Перекладываем камни m раз по такому алгоритму:

а)Берем 3 камня, лежащие по часовой стрелке от текущего.

б)Находим среди камней на песке камень с максимальным числом меньше текущего. Если камней меньше текущего нет, вместо этого просто находим камень с максимальным числом.

в)Кладем 3 камня из руки (сохраняя порядок) по часовой стрелке после найденного.

г)Новый текущий камень — следующий за последним положенным.

Какой порядок камней после этих операций?