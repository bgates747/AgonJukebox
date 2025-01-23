import os

def write_raw_song_list(song_names, output_file):
    """
    Writes song names as raw bytes, padded to 256 characters, to a binary file.
    """
    # Ensure the output directory exists
    os.makedirs(os.path.dirname(output_file), exist_ok=True)

    # Open the output file for writing in binary mode
    with open(output_file, "wb") as f:
        for song in song_names:
            # Strip leading/trailing whitespace and encode as ASCII
            ascii_values = [ord(c) for c in song.strip()]

            # Pad the ASCII values to 256 characters with zeroes
            padded_values = ascii_values + [0] * (256 - len(ascii_values))

            # Write the padded values as raw bytes to the file
            f.write(bytes(padded_values))

if __name__ == "__main__":
    # Input: Replace this with your multi-line song list
    input_songs = """
zzz002.wav
zzz003.wav
zzz004.wav
zzz005.wav
zzz006.wav
zzz007.wav
zzz008.wav
zzz009.wav
zzz010.wav
zzz011.wav
zzz012.wav
zzz013.wav
zzz014.wav
zzz015.wav
zzz016.wav
zzz017.wav
zzz018.wav
zzz019.wav
zzz020.wav
zzz021.wav
zzz022.wav
zzz023.wav
zzz024.wav
zzz025.wav
zzz026.wav
zzz027.wav
zzz028.wav
zzz029.wav
zzz030.wav
zzz031.wav
zzz032.wav
zzz033.wav
zzz034.wav
zzz035.wav
zzz036.wav
zzz037.wav
zzz038.wav
zzz039.wav
zzz040.wav
zzz041.wav
zzz042.wav
zzz043.wav
zzz044.wav
zzz045.wav
zzz046.wav
zzz047.wav
zzz048.wav
zzz049.wav
zzz050.wav
zzz051.wav
zzz052.wav
zzz053.wav
zzz054.wav
zzz055.wav
zzz056.wav
zzz057.wav
zzz058.wav
zzz059.wav
zzz060.wav
zzz061.wav
zzz062.wav
zzz063.wav
zzz064.wav
zzz065.wav
zzz066.wav
zzz067.wav
zzz068.wav
zzz069.wav
zzz070.wav
zzz071.wav
zzz072.wav
zzz073.wav
zzz074.wav
zzz075.wav
zzz076.wav
zzz077.wav
zzz078.wav
zzz079.wav
zzz080.wav
zzz081.wav
zzz082.wav
zzz083.wav
zzz084.wav
zzz085.wav
zzz086.wav
zzz087.wav
zzz088.wav
zzz089.wav
zzz090.wav
zzz091.wav
zzz092.wav
zzz093.wav
zzz094.wav
zzz095.wav
zzz096.wav
youd_better_you_bet.wav
wild_wild_west.wav
Whitney_Houston_One_Moment_In_Time.wav
Whitney_Houston_I_Wanna_Dance_With_Somebody.wav
Whitney_Houston_Greatest_Love_Of_All.wav
Whatta_Man.wav
We_Built_This_City.wav
Walking_On_Sunshine.wav
walking_in_memphis.wav
Tina_Turner_Whats_Love_Got_To_Do_With_It.wav
Tina_Turner_Simply_The_Best.wav
Tina_Turner_River_Deep_Mountain_High.wav
time_after_time.wav
The_Police_Roxanne.wav
The_Police_Message_In_A_Bottle.wav
The_Police_Every_Breath_You_Take.wav
The_Final_Countdown.wav
The_Eagles_Take_It_Easy.wav
The_Eagles_Lyin_Eyes.wav
The_Eagles_Hotel_California.wav
The_Bee_Gees_Stayin_Alive.wav
The_Bee_Gees_Night_Fever.wav
The_Bee_Gees_How_Deep_Is_Your_Love.wav
Take_On_Me.wav
take_me_home_tonight.wav
Sweet_Freedom.wav
Summer_Of_69.wav
Stevie_Wonder_Superstition.wav
Stevie_Wonder_I_Just_Called_To_Say_I_Love_You.wav
Stevie_Wonder_Higher_Ground.wav
she_works_hard_for_the_money.wav
she_blinded_me_with_science.wav
running_on_empty.wav
Queen_We_Will_Rock_You.wav
Queen_Dont_Stop_Me_Now.wav
Queen_Bohemian_Rhapsody.wav
Private_Dancer.wav
Prince_When_Doves_Cry.wav
Prince_Raspberry_Berret.wav
Prince_Little_Red_Corvette.wav
Phil_Collins_Sussudio.wav
Phil_Collins_In_The_Air_Tonight.wav
Phil_Collins_Against_All_Odds.wav
Owner_of_a_Lonely_Heart.wav
Never_Gonna_Give_You_Up.wav
More_Than_A_Feeling.wav
missing.wav
Michael_Jackson_Thriller.wav
Michael_Jackson_Black_Or_White.wav
Michael_Jackson_Billie_Jean.wav
Material_Girl.wav
Maniac.wav
Madonna_Vogue.wav
Madonna_Material_Girl.wav
Madonna_Like_A_Prayer.wav
Love_is_a_Battlefield.wav
Lets_Go_Crazy.wav
kiss.wav
Kiss_on_My_List.wav
Just_the_Way_You_Are.wav
Jump.wav
jack_and_diane.wav
I_Want_To_Break_Free.wav
Islands_in_the_Stream.wav
Into_the_Groove.wav
I_Just_Called_to_Say_I_Love_You.wav
I_Cant_Go_for_That.wav
hurts_so_good.wav
How_Deep_Is_Your_Love.wav
higher_love.wav
Here_Comes_The_Sun.wav
heat_of_the_moment.wav
Hall_And_Oates_You_Make_My_Dreams.wav
Hall_And_Oates_Rich_Girl.wav
Hall_And_Oates_Maneater.wav
Glory_Days.wav
George_Michael_One_More_Try.wav
George_Michael_Father_Figure.wav
George_Michael_Faith.wav
Footloose.wav
Fleetwood_Mac_Landslide.wav
Fleetwood_Mac_Go_Your_Own_Way.wav
Fleetwood_Mac_Dont_Stop.wav
fields_of_gold.wav
faithfully.wav
Eye_Of_The_Tiger.wav
every_rose_has_its_thorn.wav
Every_Little_Thing_She_Does_Is_Magic.wav
Elton_John_Your_Song.wav
Elton_John_Tiny_Dancer.wav
Elton_John_Rocket_Man.wav
drive.wav
Do_You_Really_Want_to_Hurt_Me.wav
Dont_Stop_Til_You_Get_Enough.wav
Dont_Stop_Believin.wav
dancing_in_the_moonlight.wav
Cyndi_Lauper_True_Colors.wav
Cyndi_Lauper_Time_After_Time.wav
Cyndi_Lauper_Girls_Just_Want_To_Have_Fun.wav
Come_on_Eileen.wav
Chicago_Saturday_In_The_Park.wav
Chicago_If_You_Leave_Me_Now.wav
Chicago_Hard_To_Say_Im_Sorry.wav
celebration.wav
Careless_Whisper.wav
Cant_Hurry_Love.wav
Bruce_Springsteen_Thunder_Road.wav
Bruce_Springsteen_Dancing_In_The_Dark.wav
Bruce_Springsteen_Born_To_Run.wav
Borderline.wav
Billy_Joel_We_Didnt_Start_The_Fire.wav
Billy_Joel_Uptown_Girl.wav
Billy_Joel_Piano_Man.wav
Bette_Davis_Eyes.wav
All_Night_Long.wav
All_My_Life.wav
Africa.wav
ABBA_Waterloo.wav
ABBA_Mamma_Mia.wav
ABBA_Dancing_Queen.wav
20_You_Belong_To_The_City.wav
20_True.wav
19_Sister_Christian.wav
19_Missing_You.wav
18_St_Elmos_Fire.wav
18_Stay.wav
17_Let_The_Music_Play.wav
17_Electric_Avenue.wav
16_Shake_It_Up.wav
16_If_You_Could_Read_My_Mind.wav
15_Let_My_Love_Open_The_Door.wav
15_Breakfast_At_Tiffanys.wav
14_Youre_The_One_That_I_Want.wav
14_Rock_With_You.wav
13_Wake_Me_Up_Before_You_GoGo.wav
13_One_Way_Or_Another.wav
12_Take_Me_To_The_River.wav
12_Like_A_Virgin.wav
11_Keep_On_Loving_You.wav
11_Dont_Dream_Its_Over.wav
10_Hungry_Like_The_Wolf.wav
10_Hold_The_Line.wav
09_Video_Killed_The_Radio_Star.wav
09_Cruel_Summer.wav
08_Spirit_In_The_Sky.wav
08_Shadows_Of_The_Night.wav
07_I_Ran_So_Far_Away.wav
07_Forever_Young.wav
06_Sledgehammer.wav
06_Every_Little_Step.wav
05_Hooked_On_A_Feeling.wav
05_Heaven_Is_A_Place_On_Earth.wav
04_The_Power_Of_Love.wav
04_Somebody_To_Love.wav
03_Everybody_Wants_To_Rule_The_World.wav
03_All_She_Wants_To_Do_Is_Dance.wav
02_Livin_On_A_Prayer.wav
02_Life_In_The_Fast_Lane.wav
01_Its_Still_Rock_And_Roll_To_Me.wav
01_Another_One_Bites_The_Dust.wav
"""

    # Convert the input into a list of song names
    song_list = input_songs.strip().split("\n")

    # Output file path
    output_path = "src/asm/song_list.dat"

    # Write the raw song list to the binary file
    write_raw_song_list(song_list, output_path)