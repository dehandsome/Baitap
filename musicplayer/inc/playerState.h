#ifndef PLAYER_STATE_H
#define PLAYER_SATE_H

struct MusicPlayer;

typedef struct{
   void (*pressPlay)(PlayerState *state);
   void (*pressPause)(PlayerState *state);
   void (*pressStop)(PlayerState *state);
   void (*setContext)(PlayerState *state, struct MusicPlayer *player);

   struct MusicPlayer *player;
}PlayerState;
#endif 