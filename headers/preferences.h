#ifndef PREFERENCES_H
#define PREFERENCES_H

/*
* Sex
*/
#define FEMALE 0
#define MALE 1

/*
* Training style
*/
#define BODYBUILDING 0
#define POWERLIFTING 1
#define CALISTHENICS 2
#define CROSSFIT 3
#define CARDIO_ONLY 4
/*
* Weight objectives
*/
#define LOSE_WEIGHT -10
#define MANTAIN_WEIGHT 0
#define GAIN_WEIGHT 10

/*
* Workout times
*/
// 6:01 - 9:00
#define MORNING_FIRST 0609

// 9:01 - 12:00
#define MORNING_SECOND 0912

// 12:01 - 15:00
#define NOON 1215

// 15:01 - 19:00
#define AFTERNOON 1519

// 19:01 - 00:00
#define EVENING 1924

// 00:01 - 6:00
#define NIGHT 2406

/*
* Body parts
*
* IDs generated with ASCII characters
*/
#define ARMS 1
#define BACK 2
#define CHEST 3
#define LEGS 4
#define GLUTES 5
#endif  