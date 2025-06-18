#ifndef MUSIC_PLAYER_H
#define MUSIC_PLAYER_H

#include "playerState.h"
typedef struct {
    PlayerState *currentState;
    void (*changeState)(struct MusicPlayer *player, PlayerState *newState);

    void (*clickPlayButton)(struct MusicPlayer *player);
    void (*clickPauseButton)(struct MusicPlayer *player);
    void (*clickStopButton)(struct MusicPlayer *player);
}MusicPlayer;

MusicPlayer* musicPlayerCreate(PlayerState *initialState);

void musicPlayerDestroy(MusicPlayer *player);

#endif