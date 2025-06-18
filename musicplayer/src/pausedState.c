#include <stdio.h>
#include <stdlib.h>
#include"../inc/stoppedState.h"
#include"../inc/playingState.h"
#include"../inc/musicPlayer.h"
#include"../inc/playerState.h"
static void pressPlay(PlayerState *state) {
    printf("Music resumeing\n");
    state->player->changeState(state->player, playingStateCreate());
}
static void pressPause(PlayerState *state) {
    printf("Music is already paused\n");
    
}
static void pressStop(PlayerState *state) {
    printf("Music is stopped.\n");
    state->player->changeState(state->player, stoppedStateCreate());
}
static void setContext(PlayerState *state, struct MusicPlayer *player) {
    state->player = player;
}

PlayerState* pausedStateCreate() {
    PlayerState *state = (PlayerState*)malloc(sizeof(PlayerState));
    state->pressPlay = pressPlay;
    state->pressPause = pressPause;
    state->pressStop = pressStop;
    state->setContext = setContext;
    state->player = NULL;
    return state;
}