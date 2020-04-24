#include "sp_midi.h"

int main()
{
    // Aon = list_to_binary("/*/note_on").
    // Mon = <<Aon/binary, <<0, 0, 44, 105, 105, 105, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 64, 0, 0, 0, 100>>/binary >>.
    // Aoff = list_to_binary("/*/note_off").
    // Moff = << Aoff / binary, <<0, 44, 105, 105, 105, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 64, 0, 0, 0, 100>>/binary >> .

    char *osc_string_on = "/*/note_on\x00\x00,iii\x00\x00\x00\x00\x00\x00\x00\x01\x00\x00\x00\x40\x00\x00\x00\x60";
    char *osc_string_off = "/*/note_off\x00,iii\x00\x00\x00\x00\x00\x00\x00\x01\x00\x00\x00\x40\x00\x00\x00\x60";
    
    sp_midi_init();
    sp_midi_send(osc_string_on, 32);
    getchar();
    sp_midi_send(osc_string_off, 32);

    sp_midi_deinit();

}