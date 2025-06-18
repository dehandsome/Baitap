#include <stdio.h>
#include <stdlib.h>
#include"../inc/stoppedState.h"
#include"../inc/playingState.h"
#include"../inc/musicPlayer.h"
#include"../inc/playerState.h"

static void pressPlay(PlayerState *state) {
    printf("Music is already playing\n");
    
}
static void pressPause(PlayerState *state) {
    printf("Music is paused\n");
    state->player->changeState(state->player, pausedStateCreate());
}
static void pressStop(PlayerState *state) {
    printf("Music is stopped.\n");
    state->player->changeState(state->player, stoppedStateCreate());
}
static void setContext(PlayerState *state, struct MusicPlayer *player) {
    state->player = player;
}

PlayerState* playingStateCreate() {
    PlayerState *state = (PlayerState*)malloc(sizeof(PlayerState));
    state->pressPlay = pressPlay;
    state->pressPause = pressPause;
    state->pressStop = pressStop;
    state->setContext = setContext;
    state->player = NULL;
    return state;
}