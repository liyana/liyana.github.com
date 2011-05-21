#include <stdio.h>
#include <stdlib.h>
#include <sqlite3.h>

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


int main(void)
{
	int i, id, age;
	char gender[15];
	int j;
	char name[15];
	char *sql0 = NULL;
	char *sql = NULL;
	char *sql1 = NULL;
	char *sql2 = NULL;

	sqlite3 *db = NULL;
	char *err = 0;
	int ret = 0;
	int empty = 1;

	ret = sqlite3_open("./test.db", &db);
	if (ret != SQLITE_OK) {
		fputs(sqlite3_errmsg(db), stderr);
		fputs("\n", stderr);
		exit(1);
	}
	sql0 =
	    sqlite3_mprintf
	    ("create table student(id integer primary key,name text,gender text,age integer);");
	ret = sqlite3_exec(db, sql0, 0, 0, &err);
	if (ret != SQLITE_OK) {
		fputs(sqlite3_errmsg(db), stderr);
		fputs("\n", stderr);
		exit(1);
	}
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
			ret =
			    sqlite3_exec(db, "select *from student;",
					 rscallback, &empty, &err);

			if (ret != SQLITE_OK) {
				fputs(err, stderr);
				fputs("\n", stderr);
				sqlite3_close(db);
				exit(1);
			}
			printf("\n");
			break;

		case 2:
			printf("Please input id name gender age:\n");
			scanf("%d %s %s %d", &id, name, gender, &age);
			sql =
			    sqlite3_mprintf
			    ("insert into student (id,name,gender,age)values(%d,%Q,%Q,%d);",
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
			break;

		case 3:{
				printf("1.Delete by ID\n");
				printf("2.Delete by name\n");
				printf("Your choice:");
				scanf("%d", &j);
				switch (j) {
				case 1:
					printf("Please input the ID:");
					scanf("%d", &id);
					sql1 =
					    sqlite3_mprintf
					    ("delete from student where id=%d;",
					     id);
					ret =
					    sqlite3_exec(db, sql1, 0, 0,
							 &err);
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
					scanf("%s", name);
					sql2 =
					    sqlite3_mprintf
					    ("delete from student where name =%Q;",
					     name);
					ret =
					    sqlite3_exec(db, sql2, 0, 0,
							 &err);
					if (ret != SQLITE_OK) {
						fputs(err, stderr);
						fputs("\n", stderr);
						sqlite3_close(db);
						exit(1);
					}
					sqlite3_free(sql2);
					printf("\n");
					break;

				}
			}
			break;

		case 4:
			exit(0);
			break;
		}

	}







	if (empty) {
		fputs("table student is empty\n", stderr);
		exit(1);
	}

	sqlite3_close(db);
	return 0;
}
