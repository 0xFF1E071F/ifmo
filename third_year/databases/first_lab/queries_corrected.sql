1.
alter session set NLS_DATE_FORMAT = 'dd.mm.yyyy HH24:mi:ss';
SELECT * FROM �_������;
2.
SELECT DISTINCT ������������ FROM �_����������;
3.
#select ����_�������� from �_���� where rownum <= 1
#select DATEDIFF(day, '2017-08-01 00:00:00', '2017-09-01 00:00:00')
#SELECT TO_DATE('05.07.2007 09:53:01')-TO_DATE('05.08.2007 09:53:01') FROM �_����;
#SELECT TO_DATE('05.07.2007 09:53:01')-TO_DATE('05.08.2007 09:53:01') AS DIFF FROM �_���� where rownum<=1;
#SELECT TO_DATE('01.09.2017 00:00:00')-(select ����_�������� from �_���� where rownum <= 1) AS DIFF FROM �_���� where rownum<=1;
SELECT TO_DATE('01.09.2017 00:00:00')-(select * from (select ����_�������� from �_���� order by dbms_random.value) where rownum <= 1) AS DIFF FROM �_���� where rownum<=1;
4.
select �������||' '||SUBSTR(���,1,1)||'.'||SUBSTR(��������,1,1)||'.' �������_�_�������� from �_���� 
where EXTRACT(month from ����_��������) = (select * from (select EXTRACT(month from ����_��������) ����� from �_���� order by dbms_random.value) where rownum<=1);
5.
SELECT SUBSTR((select * from (select ������� from �_���� order by dbms_random.value) where rownum<=1),1,2)||'%' FROM �_����;
select �������||' '||���||' '||�������� ���, �� FROM �_���� 
where ������� LIKE SUBSTR((select * from (select ������� from �_���� order by dbms_random.value) where rownum<=1),1,2)||'%' and rownum <= 75 order by ��� DESC;
6.
select �������, ���, ��������, �� from �_���� where ��� NOT LIKE '�%' and ��� NOT LIKE '�%' and ��� NOT LIKE '�%' and ��� NOT LIKE '�%' and ��� NOT LIKE '�%'
and �������� NOT LIKE '�%' and �������� NOT LIKE '�%' and �������� NOT LIKE '�%' and �������� NOT LIKE '�%' and �������� NOT LIKE '�%';

select �������, ���, ��������, �� from �_���� where SUBSTR(���,1,1) != '�' and SUBSTR(���,1,1) != '�' 
and SUBSTR(���,1,1) != '�' and SUBSTR(���,1,1) != '�' and SUBSTR(���,1,1) != '�'
and �������� NOT LIKE '�%' and �������� NOT LIKE '�%' and �������� NOT LIKE '�%' and �������� NOT LIKE '�%' and �������� NOT LIKE '�%';
7.
select DISTINCT count(��) COUNT FROM �_���� where ��� = (select * from (select ��� from �_���� order by dbms_random.value) where rownum<=1);
8.
select CAST(������ AS INT)*2 ���������_������ from (select ������ from �_��������� 
where ����_�� = CAST((
    select * from (
        select �� from �_���� 
        order by dbms_random.value
    ) where rownum<=1
) AS INT) AND ������ IN ('3','4','5'));
9.
with
extra as (select * from (select �� from �_���� order by dbms_random.value) where rownum<=7)
select ����_��, SUM(������) from (
    select ����_��,
    case when ������ IN ('3','4','5') then ������ else '0' end ������
    from �_��������� union all (select * from (extra cross join (select '0' ������ from dual)))
)
where ����_�� IN (select * from extra)
group by ����_��;
11.
with
people_fragment as (select ��, ���, �������, �������� from �_����),
marks_fragment as (select ����_�� ��, AVG(������) �������_������ from (
    select ����_��, ������
    from �_���������
    where ������ IN ('3','4','5')
) group by ����_��),
main_table as (select people_fragment.��, ���, �������, ��������, �������_������
from (people_fragment inner join marks_fragment on people_fragment.�� = marks_fragment.��)),
max_by_families as (select �������, MAX(�������_������) ����_������ from main_table group by �������),
clean_table as (select * from main_table where (�������, �������_������) not in (select �������, ����_������ �������_������ from max_by_families))
select * from (select �������, ���, ��������, �������_������ from clean_table order by dbms_random.value) where rownum<=7;
12.
with
threes as (select ����_�� �� from �_��������� where ������ = '3'),
fours as (select ����_�� �� from �_��������� where ������ = '4'),
fives as (select ����_�� �� from �_��������� where ������ = '5'),
people as (select ������� from �_���� 
where �� in (select * from threes) and �� in (select * from fours) and �� in (select * from fives) order by dbms_random.value),
random_people as (select * from (select * from people order by dbms_random.value) where rownum<=7),
avg_mark as (select AVG(������) ��� from (select ������ from �_��������� where ������ in ('4','5'))),
avg_dist as (select AVG(UTL_MATCH.EDIT_DISTANCE(�������, '������')) ��� from random_people),
num_of_marks as (select COUNT(������) ��� from (select ������ from �_��������� where ������ in ('4','5'))),
random_year as (select * from (select ������, ����� from �_�������_���� order by dbms_random.value) where rownum <= 1),
marks_count as (select COUNT(����) ��� from random_year, �_��������� where ������ = '�����' and ���� > ������ and ���� < �����),
first_row as (select '������ 4 � 5 �� ���� ������������' ������������, ROUND(avg_mark.���,2) �������_������, num_of_marks.��� ����������_������ 
from dual, avg_mark, num_of_marks),
second_row as (select '������ "�����" � ������������ ������� ���� �� ���� ������������' ������������, 
null �������_������, marks_count.��� ����������_������ from dual, marks_count),
third_row as (select '���������� ����������� �� ����� ������� �� ������� 10 ������, ������� ������ 3, 4 � 5' ������������, 
ROUND(avg_dist.���, 2) �������_������, null ����������_������ from dual, avg_dist)
select * from (((select * from first_row) union all (select * from second_row)) union all (select * from third_row));
13.
with
ids as (select distinct ����_�� from �_��������� where ������ IN ('3','4') and TO_DATE('01.09.06') < ���� and TO_DATE('20.07.07') > ����)
select �������||' '||���||' '||�������� ��� from �_���� where �� in (select * from ids) order by ���;
14.
with
random_id as (select * from (select �� from �_���� order by dbms_random.value) where rownum<=1),
sum_random_id as (select SUBSTR(��,1,1)+SUBSTR(��,2,1)+SUBSTR(��,3,1)+SUBSTR(��,4,1)+SUBSTR(��,5,1)+SUBSTR(��,6,1) ��� from random_id),
peop_sum as (select * from (select SUM(������) ���, 
����_�� from �_���������, sum_random_id where ������ in ('3','4','5') group by ����_��), sum_random_id),
peop_needed as (select ����_�� from peop_sum where ��� > ���),
repeatings as (select * from (select COUNT(���) ����������, ��� 
from (select �������||' '||���||' '||�������� ��� from �_����) group by ��� order by ���������� desc) where ���������� > 1),
peop_fio as (select �������||' '||���||' '||�������� ���, �� from �_����)
select ��, repeatings.��� from (repeatings inner join peop_fio on repeatings.��� = peop_fio.���) where �� in (select * from peop_needed);