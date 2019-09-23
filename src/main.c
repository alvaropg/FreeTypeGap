#include <fontconfig/fontconfig.h>
#include <ft2build.h>
#include FT_FREETYPE_H
#include <time.h>

int main(int argc, char *argv[])
{
        clock_t t;
        double time_taken;
        unsigned int measure_num = 0;
        int error;
        FT_Library library;
        FT_Face face;
        FcBool fcError;

        t = clock();
        fcError = FcInit();
        if (fcError != FcTrue) {
                printf("Can't initialize FontConfig\n");
                return -1;
        }
        t = clock() - t;
        time_taken = ((double) t) / CLOCKS_PER_SEC;
        printf("%d FontConfig init took %f seconds\n", measure_num++, time_taken);

        t = clock();
        error = FT_Init_FreeType(&library);
        if (error != FT_Err_Ok) {
                printf("Error initializing FreeType library\n");
                return error;
        }
        t = clock() - t;
        time_taken = ((double) t) / CLOCKS_PER_SEC;
        printf("%d FreeType init took %f seconds\n", measure_num++, time_taken);

        t = clock();
        error = FT_New_Face(library,
                            "/home/alvaropg/work/tmp/freetype/fonts/FiraSans/FiraSans-Medium.ttf",
                            0,
                            &face);
        if (error == FT_Err_Unknown_File_Format) {
                printf("Unknown file format\n");
                return error;
        } else if (error != FT_Err_Ok) {
                printf("Error loading font: %d\n", error);
                return error;
        }
        t = clock() - t;
        time_taken = ((double) t) / CLOCKS_PER_SEC;
        printf("%d Face load took %f seconds\n", measure_num++, time_taken);

        FcFini();

        return 0;
}
