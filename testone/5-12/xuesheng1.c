#include <stdio.h>
#include <stdlib.h>
#include <sqlite3.h>
#include <string.h>
sqlite3 *db = NULL;
char *err = 0;
int ret = 0;
int empty = 1;
void empty_cache()
{
	char ch;
	ch = getchar();
	while (ch != EOF && ch != '\n') {
		ch = getchar();
	}
}

int rscallback(void *p, int argc, char **argv, char **argvv)
{
	int k;
	*(int *) p = 0;
	for (k = 0; k < argc; k++) {
		printf("%s=%s ", argvv[k], argv[k] ? argv[k] : "NULL");
	}
	putchar('\n');
	return 0;
}

int xianshi()
{

	ret = sqlite3_exec(db, "select *from student1;",
			   rscallback, &empty, &err);

	if (ret != SQLITE_OK) {
		fputs(err, stderr);
		fputs("\n", stderr);
		sqlite3_close(db);
		exit(1);
	}

         
	if (empty) {
		fputs("table student1 is empty\n", stderr);
		exit(1);
	}
	printf("\n");
}

int charu()
{
	int id, age, m;
	char gender[7] = { 0 };
	char name[20] = { 0 };


	char *sql = NULL;
      start:printf("Please input id name gender age:\n");

	empty_cache();

	if (4 != scanf("%d %20s %s %d", &id, name, gender, &age))
		goto start;


	if (id < 0 || id > 1000 || age < 0 || age > 100)
		goto start;

	if (strcmp(gender, "male") != 0 && strcmp(gender, "female") != 0)
		goto start;

	for (m = 0; name[m]; m++) {
		if (name[m] >= 'a' && name[m] <= 'z' || name[m] >= 'A'
		    && name[m] <= 'Z')
			goto next;
		else
			goto start;
	}
      next:sql =
	    sqlite3_mprintf
	    ("insert into student1(id,name,gender,age)values(%d,%Q,%Q,%d);",
	     id, name, gender, age);
	ret = sqlite3_exec(db, sql, 0, 0, &err);
	if (ret != SQLITE_OK) {
		fputs(err, stderr);
		fputs("\n", stderr);
		sqlite3_close(db);
		exit(1);
	}
	sqlite3_free(sql);
	printf("\n");
}

int shanchu()
{
	int j, id;
	char name[20] = { 0 };
	char *sql1 = NULL;
	char *sql2 = NULL;


	printf("1.Delete by ID\n");
	printf("2.Delete by name\n");
	printf("Your choice:");
	empty_cache();
	scanf("%d", &j);
	switch (j) {
	case 1:
	      l0:printf("Please input the ID:");
		empty_cache();
		scanf("%d", &id);

		if (id < 0 || id > 1000){printf("id 超出范围，请重新输入");goto l0;}
			
		sql1 =
		    sqlite3_mprintf
		    ("delete from student1 where id=%d;", id);
		ret = sqlite3_exec(db, sql1, 0, 0, &err);
		if (ret != SQLITE_OK) {
			fputs(err, stderr);
			fputs("\n", stderr);
			sqlite3_close(db);
			exit(1);
		}
		sqlite3_free(sql1);
		printf("\n");

		break;

	case 2:
		printf("Please input the name:");
		empty_cache();
		scanf("%s", name);

		sql2 =
		    sqlite3_mprintf
		    ("delete from student1 where name =%Q;", name);
		ret = sqlite3_exec(db, sql2, 0, 0, &err);
		if (ret != SQLITE_OK) {
			fputs(err, stderr);
			fputs("\n", stderr);
			sqlite3_close(db);
			exit(1);
		}
		sqlite3_free(sql2);
		printf("\n");
		break;
       default:break;
	}
}

int main(void)
{


	int i;
	char *sql0 = NULL;

	ret = sqlite3_open("./test.db", &db);
	if (ret != SQLITE_OK) {
		fprintf(stderr, "Can't open database :%s",
			sqlite3_errmsg(db));
		sqlite3_close(db);
		exit(1);
	}


	sql0 =
	    sqlite3_mprintf
	    ("create table student1(id integer primary key,name text,gender text,age integer);");


	ret = sqlite3_exec(db, sql0, 0, 0, &err);

	//   printf("%s\n",err);
	sqlite3_free(sql0);


	while (1) {
		printf("1.Display all records\n");
		printf("2.Insert Record\n");
		printf("3.Delete Record\n");
		printf("4.Exit\n");
		printf("Please Select [1-4]:");
              
		scanf("%d", &i);

		switch (i) {
		case 1:
			xianshi();
                        empty_cache();
			break;

		case 2:
			charu();
			empty_cache();
			break;

		case 3:
			shanchu();
			empty_cache();
			break;

		case 4:
			exit(0);
			break;

		default:
			empty_cache();
			break;
		}

	}


	sqlite3_close(db);
	return 0;
}
