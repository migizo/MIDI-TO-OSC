/*
  ==============================================================================

    CustomizableThread.h
    Created: 29 Mar 2021 3:14:05pm
    Author:  migizo
    reference : https://qiita.com/hotwatermorning/items/0b4b8a76371d16d05150

  ==============================================================================
*/

#pragma once

/** 任意の処理をクラス外から設定できるスレッドクラス
*/
class CustomizableThread : public juce::Thread
{
public:
    /** コンストラクタ

        @param threadName スレッドに設定する名前
    */
    CustomizableThread(juce::String threadName)
        :   juce::Thread(threadName)
    {}

    /** スレッド起動時に呼び出されるコールバック

        このコールバックの引数には、スレッドを起動した CustomizableThread 自身の参照が渡される。

        @pre startThread() を呼び出すより前に有効な関数をセットしておくこと。
        @note スレッドの実行中にこの変数が書き換えられないように注意すること。
    */
    std::function<void(CustomizableThread &self)> onRun;

private:
    void run() override
    {
        try
        {
            jassert(onRun != nullptr);
            onRun(*this);
        }
        catch (std::exception& e)
        {
            // スレッドの処理は例外で終了するべきではないので、
            // ここではその例外を握りつぶし、デバッグ時にはアサーションで検知できるようにする。
            jassert ("onRun should never throw." && false);
        }
    }
};
