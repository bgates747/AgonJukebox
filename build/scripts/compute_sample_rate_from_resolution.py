#!/usr/bin/env python3

import sys
import math

def pick_audio_sample_rate(width, height, fps, max_bps, desired_rate=None):
    """
    1) Compute video_bps = (width * height * fps).
       - Must already be a multiple of 60, or we bail.
    2) leftover = max_bps - video_bps
       - That’s how many bytes/sec we can allocate for audio.
    3) We want audio_rate = 60 * a for some integer a >= 0,
       so that audio_rate <= leftover.
    4) If desired_rate is given, we snap it to the nearest feasible multiple of 60
       that doesn’t exceed leftover.
       Otherwise, we pick the maximum feasible multiple of 60 <= leftover.
    Returns the chosen sample rate.
    """
    video_bps = width * height * fps
    if video_bps % 60 != 0:
        raise ValueError(f"Video bytes/sec = {video_bps} is not divisible by 60!")

    leftover = max_bps - video_bps
    if leftover < 0:
        raise ValueError(
            f"Video alone exceeds max_bps! (video_bps={video_bps}, max_bps={max_bps})"
        )

    # The biggest multiple of 60 that fits leftover is:
    max_audio_rate = (leftover // 60) * 60

    if max_audio_rate < 60:
        # Means leftover < 60 => can't even get 60 B/s
        # We'll just return 0 or raise an error.
        raise ValueError(
            f"Not enough leftover bandwidth to get even 60 B/s for audio! leftover={leftover}"
        )

    if desired_rate is None:
        # Just pick the maximum feasible
        return max_audio_rate
    else:
        # Snap desired_rate to multiple of 60, then cap at max_audio_rate.
        # 1) proposed = round(desired_rate / 60) * 60
        proposed = int(round(desired_rate / 60.0)) * 60
        # 2) clamp to [0, max_audio_rate]
        if proposed < 0:
            proposed = 0
        if proposed > max_audio_rate:
            proposed = max_audio_rate
        return proposed

if __name__ == "__main__":
    width   = 240
    height  = 180
    fps     = 4
    max_bps = 200000

    desired_rate = 16800

    chosen_sr = pick_audio_sample_rate(width, height, fps, max_bps, desired_rate)
    video_bps = width * height * fps
    leftover  = max_bps - video_bps

    print("\n--- Results ---")
    print(f"Resolution:    {width}x{height}")
    print(f"Frame Rate:    {fps} => video_bps={video_bps} (must be multiple of 60)")
    print(f"Max BPS:       {max_bps}")
    print(f"Leftover BPS:  {leftover}")
    print(f"Desired audio: {desired_rate} (if provided), snapped to multiple of 60")
    print(f"Chosen audio:  {chosen_sr}")
    print(f"Total BPS:     {video_bps + chosen_sr} (must be <= {max_bps})")
    print("(Each second divides into 60 lumps, no remainder.)")