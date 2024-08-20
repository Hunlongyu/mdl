<template>
    <n-config-provider :theme="darkTheme">
        <n-message-provider>
            <n-modal-provider>
                <Layout></Layout>
            </n-modal-provider>
        </n-message-provider>
    </n-config-provider>
</template>

<script setup>
import { onUnmounted } from 'vue'
import Layout from './components/layout.vue'
import { darkTheme } from 'naive-ui'


const checkClipboardForLink = async () => {
    const text = await jsGetClipboardText();
    console.log(text)

    // 判断是否为链接的正则表达式
    const urlPattern = new RegExp(
        '^(https?:\\/\\/)?' + // 协议
        '((([a-zA-Z\\d]([a-zA-Z\\d-]*[a-zA-Z\\d])*)\\.)+[a-zA-Z]{2,}|' + // 域名
        '((\\d{1,3}\\.){3}\\d{1,3}))' + // 或 IP 地址 (IPv4)
        '(\\:\\d+)?(\\/[-a-zA-Z\\d%_.~+]*)*' + // 端口号和路径
        '(\\?[;&a-zA-Z\\d%_.~+=-]*)?' + // 查询字符串
        '(\\#[-a-zA-Z\\d_]*)?$', // 锚点
        'i'
    )

    // if (urlPattern.test(clipboardText)) {
    //     console.log('剪贴板内容是一个链接:', clipboardText)
    // } else {
    //     console.log('剪贴板内容不是一个链接')
    // }
}

const handleFocus = () => {
    checkClipboardForLink();
}

onMounted(() => {
    window.addEventListener('focus', handleFocus)
})

onUnmounted(() => {
    window.removeEventListener('focus', handleFocus)
})
</script>

<style lang="scss" scoped>
html,
body,
#app,
.n-config-provider {
    height: 100%;
}

.container {
    height: 100%;

    .n-layout-scroll-container {
        display: flex;
        flex-direction: column;
    }
}
</style>
